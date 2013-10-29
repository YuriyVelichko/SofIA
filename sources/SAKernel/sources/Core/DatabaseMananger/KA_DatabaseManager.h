/********************************************************************************************************/
/* KA_DatabaseManager.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __KA_DatabaseManager
#define	__KA_DatabaseManager

// POSTGRE
#include <libpq-fe.h>

// SHARED
#include <Shared/Core/SA_CoreConstants.h>

// KERNEL
#include <Classes/KA_Kernel.h>


/********************************************************************************************************/
// Forward declaration:
class I_Session;


/********************************************************************************************************/
class KA_DatabaseManager
{
	private:////////////////////////////////////////////////////////////////////////////

								KA_DatabaseManager( void );					

								~KA_DatabaseManager();


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Static Methods:

								/** Returns singleton object of database manager. */
static	KA_DatabaseManager*		Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:		

								/** Returns status of the connection to the database. */
const	SA_ConnectionStatus&	get_ConnectionStatus( void )	{ return mConnStatus; }
	
		void					set_Kernel( KA_Kernel* inKernel )	{ mpKernel = inKernel; }


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:	

								/** Connects to the server, and open database. */ 
		void					Connect( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Database Methods ( DB_* ):					

		vector<SA_ObjProperty*>	DB_GetUserProperties( const String& inUserId );


	private:///////////////////////////////////////////////////////////////////////////			

static KA_DatabaseManager*		mpDatabaseManager;

		KA_Kernel*				mpKernel;

// Postgre
		
		PGconn					*mpConn;

		SA_ConnectionStatus		mConnStatus;
};


#endif // __KA_DatabaseManager
