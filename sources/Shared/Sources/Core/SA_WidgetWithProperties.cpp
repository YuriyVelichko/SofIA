/********************************************************************************************************/
/* SA_ObjectWithProperties.cpp																			*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// SHARED 
#include <Shared/Utils/SA_UtilConstants.h>

// CORE
#include <Shared/Core/SA_ObjectWithProperties.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
const vector<SA_ObjProperty*>& SA_ObjectWithProperties::get_Properties( void ) const
{
	return mProperties;
}	

/********************************************************************************************************/		
SA_ObjProperty* SA_ObjectWithProperties::get_Property( 
	const String&		inName ) const
{
	vector<SA_ObjProperty*>::const_iterator it = mProperties.begin();
	while( it != mProperties.end() )
	{
		if( (*it)->get_Name() == inName )
			return (*it);
		++it;
	}

	return GetEmptyProperty();
}

/********************************************************************************************************/
void SA_ObjectWithProperties::set_Property( 
	const String&		inName, 
	SA_Variant			inVariant )
{
	SA_ObjProperty* prop = get_Property( inName );

	if( prop )
		prop->set_Value( inVariant );
}

	
/********************************************************************************************************/
size_t SA_ObjectWithProperties::get_PropertyCount( void ) const
{
	return 0;
}

/********************************************************************************************************/
SA_ObjProperty* SA_ObjectWithProperties::get_Category( 
	const String&		inName ) const
{
	return nullptr;
}

/********************************************************************************************************/
size_t SA_ObjectWithProperties::get_CategoryCount( void ) const
{
	return 0;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Acces To Data
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
bool SA_ObjectWithProperties::GetBool( 
	const String&		inPropName ) const
{
	return get_Property( inPropName )->ToBool();
}

/********************************************************************************************************/
long SA_ObjectWithProperties::GetLong( 
	const String&		inPropName ) const
{
	return get_Property( inPropName )->ToLong();
}

/********************************************************************************************************/
String SA_ObjectWithProperties::GetString(
	const String&		inPropName ) const
{
	return get_Property( inPropName )->ToString();
}

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_PropertyCategory* SA_ObjectWithProperties::AddCategory(
	const String&		inName )
{
	return nullptr;
}

/********************************************************************************************************/
SA_ObjProperty* SA_ObjectWithProperties::AddProperty( 
	const String&		inName, 
	const SA_Variant&	inValue )
{
	SA_ObjProperty* res = get_Property( inName );
	if( !res )
	{
		res = new SA_ObjProperty( this, nullptr, inName );
		ASSERT( res );
	}

	res->set_Value( inValue );
	
	return res;
}

/********************************************************************************************************/
SA_ObjProperty* SA_ObjectWithProperties::GetEmptyProperty( void ) const
{
	static SA_ObjProperty prop;
	return &prop;
}

/********************************************************************************************************/
bool SA_ObjectWithProperties::HasProperty(
	const String&		inName ) const
{
	return false;
}