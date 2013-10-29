/********************************************************************************************************/
/* SAUI_TestStorage.cpp																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// TEST
#include <ModulesInteraction/SAUI_Test.h>
#include <ModulesInteraction/SAUI_TestStorage.h>

// STD
#include <vector>
using std::vector;


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////

/********************************************************************************************************/
SAUI_TestStorage* SAUI_TestStorage::mpTestStorage = nullptr;


/********************************************************************************************************/
SAUI_TestStorage::SAUI_TestStorage( void )
{
	
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Poperties
//////////////////////////////////////////////////////////////////////

/********************************************************************************************************/
const vector<SAUI_Test*>& SAUI_TestStorage::get_AllTests( void ) const
{
	return mTests;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Static Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SAUI_TestStorage* SAUI_TestStorage::Instance( void )
{
	if( !mpTestStorage )
		mpTestStorage = new SAUI_TestStorage;

	return mpTestStorage;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
void SAUI_TestStorage::Add( 
	const char*		inName, 
	pFun			inFun )
{
	SAUI_Test* test = new SAUI_Test( inName, inFun );

	mTests.push_back( test );
}

