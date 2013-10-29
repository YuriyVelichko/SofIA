/********************************************************************************************************/
/* KA_Factories.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2012                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED
#include <Shared/Utils/SA_UtilConstants.h>

// INTERFACES
#include <Factories/KA_Factories.h>

// CORE
#include <Classes/KA_Kernel.h>
#include <Classes/KA_Session.h>


/********************************************************************************************************/
I_Session*	GetSession( void )
{	
	KA_Kernel* kernel = KA_Kernel::Instance();	
	RETURN_IF_EMPTY( kernel, nullptr );

	return kernel->InitSession();	
}


