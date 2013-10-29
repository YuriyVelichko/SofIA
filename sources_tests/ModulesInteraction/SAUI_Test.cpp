/********************************************************************************************************/
/* SAUI_Test.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// TEST
#include <ModulesInteraction/SAUI_Test.h>

// STD
#include <string.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SAUI_Test::SAUI_Test( 
	const char*		inName, 
	pFun			inFun )
{
	mpName = new char[ strlen( inName ) ];
	strcpy( mpName, inName );
	mpFun = inFun;

	mRes = false;
}
	

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Poperties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
const char* SAUI_Test::get_Name( void )
{
	return mpName;
}

/********************************************************************************************************/
bool SAUI_Test::get_Res( void )
{
	return mRes;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
void SAUI_Test::Run( void )
{
	mRes = mpFun();
}