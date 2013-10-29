/********************************************************************************************************/
/* EGTD_String.cpp	                                                                                    */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// COMMON
#include <Shared/Common/SA_String.h>

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
String::String( void )
{
}

/********************************************************************************************************/
String::String( 
	const char*		inValue )
{
	size_t origsize			= strlen(inValue) + 1;
	const size_t newsize	= origsize * 10;
	size_t convertedChars	 = 0;

	wchar_t* wcstring = new wchar_t[newsize];

	mbstowcs_s(&convertedChars, wcstring, origsize, inValue, _TRUNCATE);	

	mBase = wcstring;	

	delete wcstring;
}

/********************************************************************************************************/
String::String(
	wchar_t*		inValue )
{
	mBase = inValue;
}

/********************************************************************************************************/
String::String( 
	long			inValue )
{

}

/********************************************************************************************************/
String::String( 
	const String&	inValue )
{
	mBase = inValue.str();
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Properties
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
String String::Empty( void )					
{
	return L""; 
}

/********************************************************************************************************/
long String::ToLong( void )
{
	return ( long )wcstol( str(), nullptr, 10 );
}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Access to base
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
const wchar_t* String::str( void ) const
{
	return mBase.c_str();
}

/********************************************************************************************************/
char* String::c_str( void ) const
{	
	size_t origsize = mBase.size();
	const size_t newsize = origsize * 10;
	size_t convertedChars = 0;
	char* nstring = new char[newsize];
	wcstombs_s(&convertedChars, nstring, origsize, mBase.c_str(), _TRUNCATE);

	return nstring;		
}

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark operators
//////////////////////////////////////////////////////////////////////

/********************************************************************************************************/
void String::operator = ( 
	const char*			inValue )
{
	if( !inValue )
		return;

	mBase.clear();

	size_t origsize			= strlen(inValue) + 1;
	const size_t newsize	= origsize * 5;
	size_t convertedChars	= 0;

	wchar_t* wcstring = new wchar_t[newsize];

	mbstowcs_s(&convertedChars, wcstring, origsize, inValue, _TRUNCATE);	
	
	mBase = wcstring;	

	delete wcstring;
}

/********************************************************************************************************/
void  String::operator = ( 
	const wchar_t*		inValue )
{
	mBase = inValue;
}

/********************************************************************************************************/
void  String::operator = ( 
	const String		inValue )
{
	mBase = inValue.str();
}

/********************************************************************************************************/
bool String::operator == (
	const wchar_t*		inValue )
{
	wstring str( inValue );

	return mBase.compare( str ) == 0;
}

/********************************************************************************************************/
bool String::operator == ( 
	const String		inValue )
{
	return mBase.compare( inValue.str() ) == 0;
}

/********************************************************************************************************/
bool String::operator != (
	const wchar_t*		 inValue )
{
	wstring str( inValue );

	return !mBase.compare( str );
}

/********************************************************************************************************/
String&	String::operator += ( 
	const wchar_t*	inValue )
{
	mBase.append( inValue );

	return *this;
}

/********************************************************************************************************/
String&	String::operator += ( 
	const String& 	inValue )
{
	mBase.append( inValue.str() );

	return *this;
}
