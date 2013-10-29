/********************************************************************************************************/
/* UtilCostatnts.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __UtilCostatnts
#define	__UtilCostatnts

// UTILS
#include <Shared/Utils/SA_Assert.h>


/********************************************************************************************************/
// Macroses

#define NAMESPACE_SAUI_BEGIN namespace SAUI_Namespace {
#define NAMESPACE_SAUI_END }

#define ASSERT( statment )								\
	SA_Assert::Assert( statment, #statment );

#define ASSERT_MSG( statment, message )					\
	SA_Assert::Assert( statment, #statment, message );

#define RETURN_VOID_IF_EMPTY( statment )			\
	if( !( statment ) ) return;

#define RETURN_IF_EMPTY( statment, retValue )			\
	if( !( statment ) ) return retValue;




#endif // __UtilCostatnts
