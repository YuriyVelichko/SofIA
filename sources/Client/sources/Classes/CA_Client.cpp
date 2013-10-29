/********************************************************************************************************/
/* CA_Client.cpp																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED
#include <Shared/Utils/SA_UtilConstants.h>

// KERNEL
#include <Kernel/Factories/KA_Factories.h>
#include <Kernel/Interfaces/I_Session.h>

// CLASSES
#include <Sources/Classes/CA_Client.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
CA_Client::CA_Client( void )
:
	mpSession	( nullptr ),
	mpUser		( nullptr )
{

}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark I_Client
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_User* CA_Client::get_User( void )
{
	return mpUser;
}

/********************************************************************************************************/
SA_ObjProperty* CA_Client::GetKernelProperty( const String& inName )
{
	return mpSession->GetKernelProperty( inName );
}

/********************************************************************************************************/
void CA_Client::InitSession( 
	const String&			inUserLogin, 
	const String&			inUserPass )
{
	mInitSessionData.mLogin = inUserLogin;
	mInitSessionData.mPass	= inUserPass;

	mpSession = GetSession();
	RETURN_VOID_IF_EMPTY( mpSession );

	mpUser = mpSession->GetUserModel( mInitSessionData );
	RETURN_VOID_IF_EMPTY( mpUser );
}



