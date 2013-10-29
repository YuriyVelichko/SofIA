/********************************************************************************************************/
/* SA_CoreConstants.h	                                                                                */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __CoreConstants
#define	__CoreConstants


/********************************************************************************************************/
enum SA_ValueType
{
	kValue_Undefined = 0,
	kValue_Bool,
	kValue_Long,
	kValue_String
};

/********************************************************************************************************/
enum SA_WidgetType
{
	kWidget_Undefined = 0,

	kWidget_CSA,
	kWidget_PushButton
};

/********************************************************************************************************/
enum SA_ConnectionStatus
{
	kConnect_Undefined = 0,
	
	kConnect_Ok,
	kConnect_Fail	
};

#endif // __CoreConstants