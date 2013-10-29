/********************************************************************************************************/
/* SA_InitSessionData.h                                                                                 */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_InitSessionData
#define	__SA_InitSessionData

// SHARED 
#include <Shared/Common/SA_String.h>


/********************************************************************************************************/
struct SAUI_API SA_InitSessionData
{
	String		mLogin;
	String		mPass;

	size_t		mUserID;
};



#endif // ____SA_InitSessionData