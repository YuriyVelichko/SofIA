/********************************************************************************************************/
/* CA_Client.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __CA_Client
#define	__CA_Client

// CLIENT
#include <Client/Interfaces/I_Client.h>

//SHARED
#include <Shared/Common/SA_String.h>
#include <Shared/Core/SA_InitSessionData.h>
#include <Shared/Core/SA_Property.h>
#include <Shared/Core/SA_User.h>


/********************************************************************************************************/
// Forward declaration:
class I_Kernel;
class I_Session;

/********************************************************************************************************/
class CA_Client : public I_Client
{
	public:////////////////////////////////////////////////////////////////////////////

								CA_Client( void );	
		
		
	public://///////////////////////////////////////////////////////////////////////////

// I_Client

	//---------------------
	// Properties:

	SA_User*				get_User( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

								/** Returns kernel property. */
		SA_ObjProperty*			GetKernelProperty( const String& inName );

								/** Setups connections with server. */
		void					InitSession( 
									const String&			inUserLogin, 
									const String&			inUserPass );		

		
	protected://////////////////////////////////////////////////////////////////////////
		
		SA_InitSessionData		mInitSessionData;

		I_Session*				mpSession;	
		SA_User*				mpUser;
};

#endif // __CA_Client


