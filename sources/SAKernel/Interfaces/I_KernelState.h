/********************************************************************************************************/
/* I_KernelState.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __I_KernelState
#define	__I_KernelState

// SHARED
#include <Shared/Common/SA_String.h>

/********************************************************************************************************/
// Forward declaration:
class SA_ObjProperty;


/********************************************************************************************************/
class SAUI_API I_KernelState
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

virtual	SA_ObjProperty*				GetKernelProperty( const String& inName ) = 0;

};

#endif // __I_KernelState