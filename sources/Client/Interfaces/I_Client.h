/********************************************************************************************************/
/* I_Client.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __I_Client
#define	__I_Client


/********************************************************************************************************/
// Forward declaration:
class	SA_ObjProperty;
class	SA_User;
class	String;


/********************************************************************************************************/
class SAUI_API I_Client
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:

		// <User> [r/o]

virtual	SA_User*				get_User( void ) = 0;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:
		
								/** Returns kernel property. */
virtual	SA_ObjProperty*			GetKernelProperty( const String& inName ) = 0;

								/** Setups connections with server. */
virtual	void					InitSession( 
									const String&			inUserLogin, 
									const String&			inUserPass ) = 0;	
};

#endif // __I_Client