/********************************************************************************************************/
/* PrivateVariant.cpp																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// PRIVATE
#include <SAShared/Private/Core/SA_PrivateVariant.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////
							

/********************************************************************************************************/
void SA_PrivateVariant::Init( 
	SA_ValueType			inType )
{
	SA_VariantData* data = new SA_VariantData;
	data->mpPtr = NULL;
	data->mType = inType;

	mpData = std::shared_ptr<SA_VariantData>( data );
}
