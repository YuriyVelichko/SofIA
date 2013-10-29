/********************************************************************************************************/
/* SAUI_Test_InitModules.cpp																			*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

#include <Client/Factories/CA_ClientFactory.h>
#include <Client/Interfaces/I_Client.h>


/********************************************************************************************************/
bool SAUI_Test_InitClient( void )
{
	CA_ClientFactory* factory = CA_ClientFactory::Instance();

	I_Client* client = factory->CreateClient();

	if( !client )
	{
		return false;
	}

	return true;
}

