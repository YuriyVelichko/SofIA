/********************************************************************************************************/
/* Property.cpp																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// CORE
#include <Shared/Core/SA_Property.h>

// UTILS
#include <Shared/Utils/SA_UtilConstants.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_ObjProperty::SA_ObjProperty( void )
{
	mpOwner = nullptr;
	mpCategory = nullptr;
}

/********************************************************************************************************/
SA_ObjProperty::SA_ObjProperty( 
	SA_ObjectWithProperties*	inOwner,
	SA_PropertyCategory*		inCategory,
	const String&				inName )
{
	ASSERT( inOwner )
	ASSERT( inCategory )
	
	mpOwner = inOwner;
	mpCategory = inCategory;
	mName = inName;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_PropertyCategory* SA_ObjProperty::get_Category( void ) const
{
	return mpCategory;
}

/********************************************************************************************************/
String SA_ObjProperty::get_Description( void ) const
{
	return mDescription;
}

/********************************************************************************************************/
void SA_ObjProperty::set_Description( 
	const String&		inValue )
{
	mDescription = inValue;
}

/********************************************************************************************************/
String SA_ObjProperty::get_Name( void ) const
{
	return mName;
}

/********************************************************************************************************/
void SA_ObjProperty::set_Name( 
	const String&		inName )
{
	mName = inName;
}

/********************************************************************************************************/
SA_ObjectWithProperties* SA_ObjProperty::get_Owner( void ) const
{
	return mpOwner;
}

/********************************************************************************************************/
SA_ValueType SA_ObjProperty::get_Type( void ) const
{
	return mType;
}

/********************************************************************************************************/
SA_Variant SA_ObjProperty::get_Value( void ) const
{
	return mValue;
}

/********************************************************************************************************/
void SA_ObjProperty::set_Value( const SA_Variant& inValue )
{
	mValue = inValue;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Access to base
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
bool SA_ObjProperty::ToBool( void ) const
{
	return mValue.ToBool();
}

/********************************************************************************************************/
long SA_ObjProperty::ToLong( void ) const
{
	return mValue.ToLong();
}

/********************************************************************************************************/
String SA_ObjProperty::ToString( void ) const
{
	return mValue.ToString();
}