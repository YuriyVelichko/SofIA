/********************************************************************************************************/
/* KA_Kernel.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __KA_Kernel
#define	__KA_Kernel

// STD
#include <memory>

//SHARED
#include <Shared/Core/SA_InitSessionData.h>
#include <Shared/Utils/LogManager/SA_LogMananger.h>

// KERNEL
#include <Interfaces/I_Session.h>
#include <Classes/KA_Kernel.h>
#include <Classes/KA_KernelState.h>
#include <Classes/KA_Session.h>


/********************************************************************************************************/
// Forward declaration
class KA_SessionManager;
class KA_DatabaseManager;


/********************************************************************************************************/
class KA_Kernel
{
	private:////////////////////////////////////////////////////////////////////////////

								KA_Kernel( void );	

	
	public://///////////////////////////////////////////////////////////////////////////

// This Class API

	//---------------------
	// Static Methods:	

static	KA_Kernel*				Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:
		
		// <KernelState> [r/o]
								/** Returns object of kernel state. */
		I_KernelState*			get_KernelState( void );

		// <LogManager> [r/o]
								/** Returns object of log manager for system. */
		SA_LogMananger*			get_LogManager( void ) const;

		// <Property> [w/o]
								/* Set property of Kernel. */
		void					set_Property( 
									const String&		inName, 
									SA_Variant			inVariant );

		// <SessionManager> [r/o]
								/** Returns object of session manager for system. */
		KA_SessionManager*		get_SessionManager( void ) const;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

								/* Create instance of user model. */
		SA_User*				CreateUser( const SA_InitSessionData& inData );

								/* Create new session. */ 
		I_Session*				InitSession( void );

								/* Method, that saves all data, cleanups resources, and turns off the kernel. */
		void 					ShotDown( void );
		
	protected://////////////////////////////////////////////////////////////////////////

	//---------------------
	// Internal Methods:

								/** Method, that initialize basic resources and prepare kernel to work. */
		void	 				Init( void );

								/** Returns code of the user in the database.
									This code is a key of user model in the database.*/
		String					GetUserHash( const SA_InitSessionData& inData );

		
	protected://////////////////////////////////////////////////////////////////////////

static	KA_Kernel*				mpKernel;

		KA_KernelState*			mpState;
			
		KA_DatabaseManager*		mpDatabaseMananger;
		SA_LogMananger*			mpLogManager;
		KA_SessionManager*		mpSessionManager;
};

#endif // __KA_Kernel


