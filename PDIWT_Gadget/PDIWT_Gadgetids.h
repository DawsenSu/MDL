#pragma once
/************************************************************************/
/* Application ID														*/
/************************************************************************/
#define DLLAPP_Gadget	1

/************************************************************************/
/* MessageList'ID														*/
/************************************************************************/
#define STRINGLISTID_Commands	0
#define STRINGLISTID_Prompts	1
#define STRINGLISTID_ERROR		2

/************************************************************************/
/* Command Name ID														*/
/************************************************************************/
#define CMDNAME_ParallelAreaTool	1
#define CMDNAME_CreateTableTool		2

/************************************************************************/
/* Prompt	ID															*/
/************************************************************************/
#define PROMPT_FirstPoint	1
#define PROMPT_NextPoint	2
#define PROMPT_AceeptPoint	3
#define PROMPT_BoxSelectPoint	4
#define PROMPT_AceeptCreatePoint	5

/************************************************************************/
/* Error string ID														*/
/************************************************************************/
#define  ERR_NOTALLOWED		1

/************************************************************************/
/* TEXTRsc	ID															*/
/************************************************************************/
#define TEXTID_OffsetWidth		1
#define TEXTID_TabelYTolerance	2

/************************************************************************/
/* CmdItemListRsc enum													*/
/************************************************************************/
enum CmdItemListId
{
	ITEMLIST_PARALLELARE = 1,
	ITEMLIST_CREATETABLE = 2
};
/************************************************************************/
/* DialogBox ID															*/
/************************************************************************/
#define	DIALOGID_Information	1

/************************************************************************/
/* Hook Function ID														*/
/************************************************************************/
#define HOOKITEMID_DgnLevels	1

/************************************************************************/
/* ComboBox Resource ID													*/
/************************************************************************/
#define  COMBOBOXID_myLevel		1

/************************************************************************/
/* public structures													*/
/************************************************************************/
struct OffSetWidth
{
	double width;
};

struct DgnLevels
{
	char levelName[512];
};

struct TableYTolerance
{
	double tolerance;
};