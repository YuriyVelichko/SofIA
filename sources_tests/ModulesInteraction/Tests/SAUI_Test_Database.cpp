/********************************************************************************************************/
/* SAUI_Test_Database.cpp																				*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

#include <Shared/Core/SA_CoreConstants.h>
#include <Shared/Core/SA_Properties.h>
#include <Shared/Core/SA_Property.h>
#include <Shared/Core/SA_User.h>

#include <Client/Factories/CA_ClientFactory.h>
#include <Client/Interfaces/I_Client.h>


/********************************************************************************************************/
bool SAUI_Test_ConnectToDB( void )
{
	CA_ClientFactory* factory = CA_ClientFactory::Instance();

	I_Client* client = factory->CreateClient();

	if( !client )
	{
		return false;
	}

	client->InitSession( L"TestLogin", L"TestPass" );

	SA_ObjProperty* connState = client->GetKernelProperty( PROP_KERNEL_CONN_STATE );
	if( !connState )
	{
		return false;
	}

	if( connState->ToLong() == kConnect_Ok )
	{
		return true;
	}

	return false;
}

/********************************************************************************************************/
bool SAUI_Test_GetUserModel( void )
{
	CA_ClientFactory* factory = CA_ClientFactory::Instance();

	I_Client* client = factory->CreateClient();

	if( !client )
	{
		return false;
	}

	client->InitSession( L"TestLogin", L"TestPass" );

	SA_User* user = client->get_User();	

	if( user->GetString( L"UserID" ) == L"7777777" && user->GetString( L"Test_Name" ) == L"Test Name" )
		return true;

	return false;
}
