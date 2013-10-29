/********************************************************************************************************/
/* KA_Session.cpp																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED
#include <Shared/Utils/SA_UtilConstants.h>

// INTERFACES
#include <Interfaces/I_KernelState.h>

// CORE
#include <Classes/KA_Kernel.h>
#include <Classes/KA_Session.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
KA_Session::KA_Session( KA_Kernel* inKernel )
:
	mpKernel( inKernel )
{
	ASSERT( mpKernel )
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark I_Session
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_ObjProperty* KA_Session::GetKernelProperty( const String& inName ) const
{
	return mpKernel->get_KernelState()->GetKernelProperty( inName );
}

/********************************************************************************************************/
SA_User* KA_Session::GetUserModel( const SA_InitSessionData& inData ) const
{
	return mpKernel->CreateUser( inData );
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////




