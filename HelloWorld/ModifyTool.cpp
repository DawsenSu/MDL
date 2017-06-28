#include "HelloWorld.h"

struct ModifyTool:DgnElementSetTool
{
private:
	bool m_isDynamics;
	DgnButtonEvent m_ev;
protected: 
	ModifyTool(int toolId) : DgnElementSetTool(toolId) { }
	virtual bool _DoGroups() override { return false; }
	virtual UsesSelection _AllowSelection() override { return DgnElementSetTool::USES_SS_None; }//���õ�ǰ�ĵ�Selection set�Ƿ���Ա�����ElemSource

	size_t GetCloseVertex(CurveLocationDetailCR location)
	{
		size_t nSegments = 1;
		if (ICurvePrimitive::CurvePrimitiveType::CURVE_PRIMITIVE_TYPE_LineString == location.curve->GetCurvePrimitiveType())
		{
			bvector<DPoint3d> const* points = location.curve->GetLineStringCP();
			nSegments = ((points->size() < 3) ? 1 : (points->size() - 1));
		}
		double uSegRange = (1.0 / nSegments);
		size_t closeVertex = (size_t)((location.fraction + (uSegRange*0.5)) / uSegRange);

		return closeVertex;
	}
	virtual bool _SetupForModify(DgnButtonEventCR ev, bool isDynamics) override//���޸�֮ǰ����
	{
		m_isDynamics = isDynamics;
		m_ev = ev;
		
		return true;
	}
	virtual StatusInt _OnElementModify(EditElementHandleR el) override
	{
		DPoint3d locatePoint;
		CurveVectorPtr curve = ICurvePathQuery::ElementToCurveVector(el);// dynamic casts hander to ICurvePathQuery and Call GetCruveVector();
		CurveLocationDetail location;

		_GetAnchorPoint(&locatePoint);
		
		if (!curve->ClosestPointBounded(locatePoint, location))
			return ERROR;

		size_t closeVertex = GetCloseVertex(location);
		ICurvePrimitivePtr& primitive = curve->front();

		switch (primitive->GetCurvePrimitiveType())
		{
			case ICurvePrimitive::CurvePrimitiveType::CURVE_PRIMITIVE_TYPE_Line:
			{
				DSegment3d segement = *primitive->GetLineCP();
				segement.point[closeVertex] = *m_ev.GetPoint();
				primitive = ICurvePrimitive::CreateLine(segement);
				break;
			}
			case ICurvePrimitive::CurvePrimitiveType::CURVE_PRIMITIVE_TYPE_LineString:
			{
				bvector<DPoint3d> points = *primitive->GetLineStringCP();
				points[closeVertex] = *m_ev.GetPoint();
				primitive = ICurvePrimitive::CreateLineString(points);
				break;
			}
		}
		ICurvePathEdit* pathEdit = nullptr;
		if (NULL != (pathEdit = dynamic_cast<ICurvePathEdit*>(&el.GetHandler())) && SUCCESS == pathEdit->SetCurveVector(el, *curve.get()))
			return SUCCESS;
		return	DraftingElementSchema::ToElement(el, *curve, &el, el.GetModelRef()->Is3d(), *el.GetModelRef());
	}

	virtual bool _OnPostLocate(HitPathCP path, WStringR canAcceptReason) override //�ж��Ƿ���Զ�λ
	{
		if (!DgnElementSetTool::_OnPostLocate(path, canAcceptReason))
			return false;

		EditElementHandle eh(path->GetHeadElem(), path->GetRoot());
		CurveVectorPtr curve = ICurvePathQuery::ElementToCurveVector(eh);

		if (!curve.IsValid()|| !curve->IsOpenPath())
		{
			canAcceptReason = WString(L"�����߻��ߴ�");
			return false;
		}
		switch (curve->HasSingleCurvePrimitive())
		{
		case ICurvePrimitive::CurvePrimitiveType::CURVE_PRIMITIVE_TYPE_Line:
		case ICurvePrimitive::CurvePrimitiveType::CURVE_PRIMITIVE_TYPE_LineString:
			return true;
		default:
			return false;
		}
	}

	virtual void _OnRestartTool() override
	{
		InstallNewInstance(GetToolId());
	}
public:
	static void InstallNewInstance(int toolId)
	{
		ModifyTool* tool = new ModifyTool(toolId);
		tool->InstallTool();
	}
};

void StartModifyTool(WCharCP	unparsed)
{
	ModifyTool::InstallNewInstance(CMDNAME_ModifyTool);
}