/********************************************************************************************************/
/* CA_ClientFactory.h                                                                                   */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// CLIENT
#include <Factories\CA_ClientFactory.h>
#include <Interfaces\I_Client.h>
#include <Sources\Classes\CA_Client.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////

CA_ClientFactory* CA_ClientFactory::mpFactory = nullptr;

/********************************************************************************************************/
CA_ClientFactory::CA_ClientFactory( void )
{

}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark I_Client
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
CA_ClientFactory* CA_ClientFactory::Instance( void )
{
	if( !mpFactory )
		mpFactory = new CA_ClientFactory;

	return mpFactory;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
I_Client* CA_ClientFactory::CreateClient( void )
{
	CA_Client* client = new CA_Client;

	return dynamic_cast<I_Client*>( client );
}
