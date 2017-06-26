/*--------------------------------------------------------------------------------------+
|
|  $Source: MstnExamples/Elements/exampleSolids/exampleSolidsCmd.r $
|
|  $Copyright: (c) 2015 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include <Mstn\MdlApi\rscdefs.r.h>
#include <Mstn\MdlApi\cmdclass.r.h>
#include "HelloWorldids.h"

/*----------------------------------------------------------------------+
	Command Names
+----------------------------------------------------------------------*/
MessageList STRINGLISTID_Commands =
{
	{
		{CMDNAME_PlaceBsSurfaceTool, "������"},
		{CMDNAME_FloodTool,	"��������"},
		{CMDNAME_MoveTool,"�ƶ�����"},
	}
};

MessageList STRINGLISTID_Prompts =
{
	{
		{PROMPT_FirstPoint,			"�����һ����"},
		{PROMPT_NextPoint,			"������һ����"},
		{PROMPT_NextPointOrReset,	"������һ������Ҽ����"},
	}
};