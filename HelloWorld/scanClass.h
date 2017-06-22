#pragma once
#include <Mstn\MstnDefs.h>		//��Ҫ����mstndefs.h
#include <Mstn\MstnPlatformAPI.h>

USING_NAMESPACE_BENTLEY
USING_NAMESPACE_BENTLEY_DGNPLATFORM
USING_NAMESPACE_BENTLEY_MSTNPLATFORM
USING_NAMESPACE_BENTLEY_MSTNPLATFORM_ELEMENT

class scanClass
{
public:
	scanClass();
	~scanClass();
	ScanCriteriaP getScp() const; //const ��Ա�����������޸����͵��е�˽�б���
	static int ref_callback(ElementRefP, CallbackArgP, ScanCriteriaP);
	void DoScan(ElementAgendaR);
	ElementAgenda DoScan();
	void SetType(UShort[6]);
private:
	ScanCriteriaP _scp;
};