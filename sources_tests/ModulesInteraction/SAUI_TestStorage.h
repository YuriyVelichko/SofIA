/********************************************************************************************************/
/* SAUI_TestStorage.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAUI_TestStorage
#define __SAUI_TestStorage

// TEST
#include <ModulesInteraction\SAUI_Test.h> 

// STD
#include <vector>
using std::vector;


/********************************************************************************************************/
class SAUI_TestStorage
{
	private:////////////////////////////////////////////////////////////////////////////

								SAUI_TestStorage( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------	
	// Properties:

const	vector<SAUI_Test*>&		get_AllTests( void ) const;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------	
	// Static Method:

static	SAUI_TestStorage*		Instance( void );

	public://///////////////////////////////////////////////////////////////////////////

	//---------------------	
	// Method:	

		void					Add( 
									const char*		inName, 
									pFun			inFun );
	

	public://///////////////////////////////////////////////////////////////////////////

static	SAUI_TestStorage*		mpTestStorage;

		vector<SAUI_Test*>		mTests;
};


#endif // __SAUI_TestStorage