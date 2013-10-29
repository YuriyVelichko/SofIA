/********************************************************************************************************/
/* KA_KernelState.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __KA_KernelState
#define	__KA_KernelState

// POSTGRE
#include <libpq-fe.h>

// SHARED
#include <Shared/Core/SA_CoreConstants.h>
#include <Shared/Core/SA_ObjectWithProperties.h>

// INTERFACES
#include <Interfaces/I_KernelState.h>


/********************************************************************************************************/
class KA_KernelState
:
	public I_KernelState,
	public SA_ObjectWithProperties
{
	private:////////////////////////////////////////////////////////////////////////////

								KA_KernelState( void );
								~KA_KernelState();


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Static Methods:

								/** Returns singleton. */
static	KA_KernelState*			Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

// SA_ObjectWithProperties API

	//---------------------
	// Methods:				

		void					CreateProperties( void );


	public://///////////////////////////////////////////////////////////////////////////

// I_KernelState API

	//---------------------
	// Methods:				

		SA_ObjProperty*			GetKernelProperty( const String& inName ) { return get_Property(  inName ); }


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:	

	protected://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Internal Methods:	


	private:///////////////////////////////////////////////////////////////////////////			

static KA_KernelState*		mpKernelState;

};


#endif // __KA_KernelState
