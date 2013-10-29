/********************************************************************************************************/
/* SAUI_Tests.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAUI_Tests
#define __SAUI_Tests

// TEST
#include <ModulesInteraction/SAUI_Test.h>
#include <ModulesInteraction/SAUI_TestStorage.h>

/********************************************************************************************************/
//Macroses
#define ADD_TEST( name )								\
	SAUI_TestStorage::Instance()->Add( #name, name );


/********************************************************************************************************/
// Test Modules
bool SAUI_Test_InitClient( void );

/********************************************************************************************************/
// Test Database 
bool SAUI_Test_ConnectToDB( void );
bool SAUI_Test_GetUserModel( void );


#endif // __SAUI_Tests