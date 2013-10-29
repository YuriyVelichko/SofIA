/********************************************************************************************************/
/* SA_Assert.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_Assert
#define	__SA_Assert


/********************************************************************************************************/
#include <SAShared\Common\SA_String.h>


/********************************************************************************************************/
class SAUI_API SA_Assert 
{
	private://///////////////////////////////////////////////////////////////////////////

								SA_Assert( void );
								SA_Assert( SA_Assert& inAssert );

	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

static	void					Assert(
									bool				inStatmentValue,
									const char*			inStatment,
									const String&		inMessage = String::Empty() );	

static	void					Assert(
									void*				inStatmentValue,
									const char*			inStatment,
									const String&		inMessage = String::Empty() );	


	protected:///////////////////////////////////////////////////////////////////////////

		//---------------------
		// Instance method:

		SA_Assert&				Instance( void );

};

#endif __SA_Assert