/********************************************************************************************************/
/* SA_Variant.cpp																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// CORE
#include <Shared/Core/SA_Variant.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_Variant::SA_Variant( void )
{
	Init( kValue_Undefined );
}

/********************************************************************************************************/
SA_Variant::SA_Variant( const char* inValue )
{
	Init( kValue_String );
	mpData->mString = inValue;
}

/********************************************************************************************************/
SA_Variant::SA_Variant( 
	bool		inValue )
{
	Init( kValue_Bool );
	mpData->mBool = inValue;
}

/********************************************************************************************************/
SA_Variant::SA_Variant( 
	long		inValue )
{
	Init( kValue_Long );
	mpData->mLong = inValue;
}

/********************************************************************************************************/
SA_Variant::SA_Variant( 
	String		inValue )
{
	Init( kValue_String );
	mpData->mString = inValue;
}

/********************************************************************************************************/
SA_Variant::SA_Variant(
	wchar_t*	inValue )
{
	Init( kValue_String );
	mpData->mString = inValue;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark properties
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_ValueType SA_Variant::get_Type( void ) const
{
	return mpData->mType;
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Access to base
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
bool SA_Variant::ToBool( void ) const
{
	switch( mpData->mType )
	{		
		case kValue_Bool		: return mpData->mBool;
		case kValue_Long		: return mpData->mLong != 0;
		case kValue_String	: return mpData->mString != L"0";

		default				: return false;
	}
}

/********************************************************************************************************/
long SA_Variant::ToLong( void ) const
{
	switch( mpData->mType )
	{		
		case kValue_Bool		: return mpData->mBool ? 1 : 0;
		case kValue_Long		: return mpData->mLong;
		case kValue_String	: return mpData->mString.ToLong();

		default				: return 0;
	}
}

/********************************************************************************************************/
String SA_Variant::ToString( void ) const
{
	switch( mpData->mType )
	{		
		case kValue_Bool		: return mpData->mBool ? L"1" : L"0";
		case kValue_Long		: return String( mpData->mLong );
		case kValue_String	: return mpData->mString;

		default				: return String::Empty();
	}
}

