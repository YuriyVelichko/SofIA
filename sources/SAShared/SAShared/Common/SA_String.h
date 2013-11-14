/********************************************************************************************************/
/* EGTD_String.h	                                                                                    */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAUI_String
#define	__SAUI_String

#include <iostream>
using namespace std;


/********************************************************************************************************/
class SAUI_API String
{
	public://///////////////////////////////////////////////////////////////////////////

								String( void );
								String( const char*		inValue );
								String( const wchar_t*  inValue );
								String( long			inValue );
								String( const String&	inValue );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:
		
								/** Returns empty string. */
static	String					Empty( void );

								/** Returns long value of the string.
								/*	If string is not a number - returns 0. */
		long					ToLong( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Access to base:
								
const	wchar_t*				str( void ) const;
		char*					c_str( void ) const;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Operators:

		void					operator = ( const char*		inValue );
		void					operator = ( const wchar_t*		inValue );
		void					operator = ( const String		inValue );

		bool					operator == ( const wchar_t*	inValue );
		bool					operator == ( const String		inValue );

		bool					operator != ( const wchar_t*	inValue );

		String&					operator += ( const wchar_t*	inValue );
		String&					operator += ( const String& 	inValue );	
			 

	protected://////////////////////////////////////////////////////////////////////////

		std::wstring			mBase;
};

inline String					operator +	( const String& str1, const String& str2 ) { String res( str1 ); return res += str2; }

#endif //__SAUI_String
