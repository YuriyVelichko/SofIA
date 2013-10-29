/********************************************************************************************************/
/* SA_PropertyCategory.cpp																				*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// CORE
#include <SAShared/Core/SA_PropertyCategory.h>

// UTILS
#include <SAShared/Utils/SA_UtilConstants.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_PropertyCategory::SA_PropertyCategory( 
	SA_ObjectWithProperties*	inOwner,
	const String&				inName,
	const String&				inDescription )
{
	ASSERT( inOwner );

	mpOwner		 = inOwner;
	mName		 = inName;
	mDescription = inDescription;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
String SA_PropertyCategory::get_Description( void ) const
{
	return mDescription;
}

/********************************************************************************************************/
void SA_PropertyCategory::set_Description( 
	const String&		inValue )
{
	mDescription = inValue;
}

/********************************************************************************************************/
String SA_PropertyCategory::get_Name( void ) const
{
	return mName;
}

/********************************************************************************************************/
void SA_PropertyCategory::set_Name( 
	const String&		inName )
{
	mName = inName;
}

/********************************************************************************************************/
SA_ObjectWithProperties* SA_PropertyCategory::get_Owner( void ) const
{
	return mpOwner;
}

/********************************************************************************************************/
const vector<SA_ObjProperty*>& SA_PropertyCategory::get_Properties( void ) const
{
	return mProperties;
}