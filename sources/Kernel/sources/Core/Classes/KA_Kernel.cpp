/********************************************************************************************************/
/* KA_Kernel.cpp																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED
#include <Shared/Utils/SA_UtilConstants.h>
#include <Shared/Core/SA_User.h>

// CLASSES
#include <Classes/KA_Kernel.h>
#include <Classes/KA_Session.h>
#include <Classes/KA_SessionManager.h>
#include <DatabaseMananger/KA_DatabaseManager.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_Kernel* KA_Kernel::mpKernel = nullptr;


/********************************************************************************************************/
KA_Kernel::KA_Kernel( void )
:
	mpState				( nullptr ),
	mpDatabaseMananger	( nullptr ),
	mpLogManager		( nullptr ),
	mpSessionManager	( nullptr )	
{
	
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Static Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_Kernel* KA_Kernel::Instance( void )
{
	if( !mpKernel )
		mpKernel = new KA_Kernel;

	mpKernel->Init();

	return mpKernel;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////



/********************************************************************************************************/
I_KernelState* KA_Kernel::get_KernelState( void )
{
	return mpState;
}

/********************************************************************************************************/
SA_LogMananger* KA_Kernel::get_LogManager( void ) const
{
	return mpLogManager;
}

/********************************************************************************************************/
void KA_Kernel::set_Property( 
	const String&		inName, 
	SA_Variant			inVariant )
{
	mpState->set_Property( inName, inVariant );
}

/********************************************************************************************************/
KA_SessionManager*	KA_Kernel::get_SessionManager( void ) const
{
	return mpSessionManager;
}

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_User* KA_Kernel::CreateUser( const SA_InitSessionData& inData )
{
	SA_User* user = new SA_User;
	user->InitProperties( mpDatabaseMananger->DB_GetUserProperties( GetUserHash( inData ) ) ); 

	return user;
}

/********************************************************************************************************/
void KA_Kernel::Init( void )
{
	// STATE 

	if( !mpState )
		mpState	= KA_KernelState::Instance();

	// DATABASE

	if( !mpDatabaseMananger )
	{
		mpDatabaseMananger = KA_DatabaseManager::Instance();

		mpDatabaseMananger->set_Kernel( this );
		mpDatabaseMananger->Connect();
	}

	// LOG

	if( !mpLogManager )
		mpLogManager = SA_LogMananger::Instance();

	// SESSION

	if( !mpSessionManager )
	{
		mpSessionManager = KA_SessionManager::Instance();
		mpSessionManager->set_Kernel( this );
	}
}

/********************************************************************************************************/
void KA_Kernel::ShotDown( void )
{

}

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Internal Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
I_Session* KA_Kernel::InitSession( void ) 
{
	RETURN_IF_EMPTY( mpSessionManager	, nullptr );
	RETURN_IF_EMPTY( mpDatabaseMananger	, nullptr );

	KA_Session* session = mpSessionManager->InitSession();

	return dynamic_cast<I_Session*>( session );
}

/********************************************************************************************************/
String KA_Kernel::GetUserHash( const SA_InitSessionData& inData )
{
	// TODO: Create function to hash input data and get user id in the database.

	return inData.mLogin;
}


