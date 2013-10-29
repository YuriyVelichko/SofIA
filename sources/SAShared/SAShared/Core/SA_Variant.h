/********************************************************************************************************/
/* SA_Variant.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_Variant
#define	__SA_Variant

// COMMON
#include <SAShared/Common/SA_String.h>

// PRIVATE
#include <SAShared/Private/Core/SA_PrivateVariant.h>


/********************************************************************************************************/
class SAUI_API SA_Variant : public SA_PrivateVariant
{
	public://///////////////////////////////////////////////////////////////////////////

								SA_Variant( void );
								
								SA_Variant( const char* inValue );
								SA_Variant( bool		inValue );
								SA_Variant( long		inValue );
								SA_Variant( String		inValue );
								SA_Variant( wchar_t*	inValue );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:

		SA_ValueType			get_Type( void ) const;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Access to base:

		bool					ToBool( void ) const;
		long					ToLong( void ) const;
		String					ToString( void ) const;
};

#endif //__SA_Variant
