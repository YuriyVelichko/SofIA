/********************************************************************************************************/
/* SA_LogMananger.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_LogMananger
#define	__SA_LogMananger

// COMMON
#include <Shared/Common/SA_String.h>

/********************************************************************************************************/
class SAUI_API SA_LogMananger
{
	protected://////////////////////////////////////////////////////////////////////////

								SA_LogMananger( void );
								SA_LogMananger( const SA_LogMananger& inObject );

								~SA_LogMananger( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Static Methods:

static	SA_LogMananger*			Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:
	

	
	protected://////////////////////////////////////////////////////////////////////////

static SA_LogMananger*		mpLogMananger;
};


#endif // __SA_LogMananger