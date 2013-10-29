/********************************************************************************************************/
/* KA_SessionManager.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __KA_SessionManager
#define	__KA_SessionManager

// KERNEL
#include <Classes/KA_Kernel.h>


/********************************************************************************************************/
// Forward declaration:
class KA_Session;


/********************************************************************************************************/
class KA_SessionManager
{
	protected://////////////////////////////////////////////////////////////////////////
		
								KA_SessionManager( void );

								~KA_SessionManager();


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Static Methods:

								/** Returns singleton object of session manager. */
static	KA_SessionManager*		Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:

		void					set_Kernel( KA_Kernel* inKernel )		{ mpKernel = inKernel; }

		
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

		KA_Session*				InitSession( void );


	private:///////////////////////////////////////////////////////////////////////////

static	KA_SessionManager*		mpSessionManager;

		KA_Kernel*				mpKernel;

};


#endif // __KA_SessionManager
