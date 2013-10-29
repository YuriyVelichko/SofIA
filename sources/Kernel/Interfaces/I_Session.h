/********************************************************************************************************/
/* I_Session.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __I_Session
#define	__I_Session

// SHARED
#include <Shared/Common/SA_String.h>


/********************************************************************************************************/
// Forward declaration
class SA_ObjProperty;
class SA_User;
struct SA_InitSessionData;


/********************************************************************************************************/
class SAUI_API I_Session
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:								


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:	

								/** Returns Kernel Property.*/  
virtual SA_ObjProperty*			GetKernelProperty( const String& inName ) const = 0;

								/** Returns inited user model.
								*	Returns NULL, if model has not be inited. */
virtual SA_User*				GetUserModel( const SA_InitSessionData& inData ) const = 0;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

};

#endif // __I_Session