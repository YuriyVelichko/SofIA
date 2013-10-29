/********************************************************************************************************/
/* main.cpp																								*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// TESTS
#include <ModulesInteraction\SAUI_TestStorage.h>
#include <ModulesInteraction\Tests\SAUI_Tests.h>

// STD
#include <iostream>
using namespace std;


void RegTests( void );

int main()
{
	RegTests();

	const vector<SAUI_Test*>& tests = SAUI_TestStorage::Instance()->get_AllTests();

	vector<SAUI_Test*>::const_iterator it = tests.begin();
	while( it != tests.end() )
	{
		(*it)->Run();

		const char* res = (*it)->get_Res() ? "Pass" : "Fail";

		cout << (*it)->get_Name() << ":\t" << res << endl;

		++it;
	}

	char q;
	cout << endl;
	cin >> q;

	return 0;
}


/********************************************************************************************************/
void RegTests( void )
{
//	ADD_TEST( SAUI_Test_InitClient );

//	ADD_TEST( SAUI_Test_ConnectToDB );
	ADD_TEST( SAUI_Test_GetUserModel );
}