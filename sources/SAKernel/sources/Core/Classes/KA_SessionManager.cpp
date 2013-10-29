/********************************************************************************************************/
/* KA_SessionManager.cpp																					*/
/*																										*/
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// KERNEL
#include <Interfaces/I_Session.h>
#include <Classes/KA_Session.h>
#include <Classes/KA_SessionManager.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_SessionManager* KA_SessionManager::mpSessionManager = nullptr;


/********************************************************************************************************/
KA_SessionManager::KA_SessionManager( void )
{
	
}

/********************************************************************************************************/
KA_SessionManager::~KA_SessionManager()
{
	delete mpSessionManager;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Static Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_SessionManager*	KA_SessionManager::Instance( void )
{
	if( mpSessionManager == nullptr )
		mpSessionManager = new KA_SessionManager;

	return mpSessionManager;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_Session* KA_SessionManager::InitSession( void )
{
	KA_Session* session = new KA_Session( mpKernel );	

	return session;
}
