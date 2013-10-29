/********************************************************************************************************/
/* KA_DatabaseManager.cpp																					*/
/*																										*/
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED
#include <Shared/Common/SA_String.h>
#include <Shared/Core/SA_Properties.h>
#include <Shared/Utils/SA_UtilConstants.h>

// KERNEL
#include <Core/DatabaseMananger/KA_DatabaseManager.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_DatabaseManager* KA_DatabaseManager::mpDatabaseManager = nullptr;


/********************************************************************************************************/
KA_DatabaseManager::KA_DatabaseManager( void )
{	
}

/********************************************************************************************************/
KA_DatabaseManager::~KA_DatabaseManager()
{
	PQfinish( mpConn ); 

	delete mpDatabaseManager;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Static Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_DatabaseManager*	KA_DatabaseManager::Instance( void )
{
	if( mpDatabaseManager == nullptr )
		mpDatabaseManager = new KA_DatabaseManager;

	return mpDatabaseManager;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
void KA_DatabaseManager::Connect( void )
{
	const char *conninfo =
			"hostaddr	= '127.0.0.1'"
			" port		= '5432'"
			" dbname	= 'SAUI_DB'"
			" user		= 'postgres'"
			" password	= 'postgres'";

    PGconn     *conn;
//  PGresult   *res;
//	int         nFields;
//	int         i, j;

	/*
	String connParams 
				= L"hostaddr	= '127.0.01'";
	connParams += L"port		= ''";
	connParams += L"dbname		= SAUI_DB";
	connParams += L"user		= 'postgres'";
	connParams += L"password	= 'postres'";
    */

    /* Make a connection to the database */
    conn = PQconnectdb( conninfo );

	ConnStatusType status = PQstatus( conn );
	if( !conn || status != CONNECTION_OK )
	{
		mConnStatus = kConnect_Fail;
		mpKernel->set_Property( PROP_KERNEL_CONN_STATE, ( long ) kConnect_Fail );
	}
	else
	{
		mConnStatus = kConnect_Ok;
		mpKernel->set_Property( PROP_KERNEL_CONN_STATE, ( long ) kConnect_Ok );
	}      

	mpConn = conn;
}

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Database Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
vector<SA_ObjProperty*> KA_DatabaseManager::DB_GetUserProperties( const String& inUserId )
{
	vector<SA_ObjProperty*> result; 	

	// SELECT DATA

	static String query = L"select * from  public.\"SAUI_Users\" where \"UserID\" = 7777777";

	PGresult* res = PQexec( mpConn, "select * from  public.\"SAUI_Users\" where \"UserID\" = 7777777" );	

	size_t rec_count = PQntuples( res );	
	ASSERT( rec_count == 1 );

	// INIT PROPERTIES

	size_t fld_count = PQnfields( res );
	for ( size_t i = 0; i < fld_count; ++i )
	{
		SA_ObjProperty* prop = new SA_ObjProperty;

		prop->set_Name( PQfname( res, i ) );
		prop->set_Value( PQgetvalue( res, 0, i ) );

		result.push_back( prop );
	}
	
	// CLEAR RESULT

	PQclear( res );	

	return result;
}



