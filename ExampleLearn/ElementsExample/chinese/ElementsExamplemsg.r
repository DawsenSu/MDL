/*--------------------------------------------------------------------------------------+
|
|     $Source: MstnExamples/Elements/exampleSolids/exampleSolidsCmd.r $
|
|  $Copyright: (c) 2015 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include <Mstn\MdlApi\rscdefs.r.h>
#include <Mstn\MdlApi\cmdclass.r.h>

#include "../ElementsExampleids.h"

MessageList STRINGLISTID_Commands =
{
	{
		{CMDNAME_ElementsExampleCreateMlineNone,	"����û�����ԵĶ���"},
		{CMDNAME_ElementsExampleCreateMlineActive,	"�������е�ǰ���ԵĶ���"},
		{CMDNAME_ElementsExampleCreateMlineCustom,	"���������Զ������ԵĶ���"},
		{CMDNAME_ElementsExampleCreateShapeNone,	"����û�����Ե���״"},
		{CMDNAME_ElementsExampleCreateShapeActive,	"�������е�ǰ���Ե���״"},
		{CMDNAME_ElementsExampleCreateShapeCustom,	"���������Զ������Ե���״"},
		{CMDNAME_ElementsExampleCopy,				"��������"},
		{CMDNAME_ElementsExampleQueryElementDisplay, "��ѯԪ����ʾ" },
		{CMDNAME_ElementsExampleQueryElementGeometry,"��ѯԪ�ؼ��γߴ�"},
		{CMDNAME_ElementsExampleQueryElementFill,	"��ѯԪ�����" },
	}
};

MessageList STRINGLISTID_Prompts =
{
	{
		{PROMPT_FristPoint,		"�����һ����"},
		{PROMPT_NextPoint,		"������һ����"},
		{PROMPT_OppsiteCorner,	"����Խǵ�"},
		{PROMPT_NextPointOrReset, "������һ���������"},
		{PROMPT_SelectElement,	"ѡ��Ҫ���Ƶ�Ԫ��"},
		{PROMPT_CopyPoint,		"����һ����������Ԫ��"},
	}
};

