/********************************************************************************************************/
/* Property.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __Property
#define	__Property

// CORE
#include <SAShared/Private/Core/SA_PrivateProperty.h>


/********************************************************************************************************/
class SAUI_API SA_ObjProperty : public SA_PrivateProperty
{
	public://///////////////////////////////////////////////////////////////////////////

								SA_ObjProperty( void );

								SA_ObjProperty( 
									SA_ObjectWithProperties*	inOwner,
									SA_PropertyCategory*		inCategory,
									const String&				inName );

	public://///////////////////////////////////////////////////////////////////////////

		//---------------------
		// Properties:

		// <Category> [r/o]
								/** Returns category of the property. */
		SA_PropertyCategory*	get_Category( void ) const;

		// <Description> [r/w]
								/** Returns description of the property. */
		String					get_Description( void ) const;
		void					set_Description( const String& inValue );

		//	<Name> [r/w]
								/** Returns name of the property. */ 
		String					get_Name( void ) const;
		void					set_Name( const String& inName );

		// <Owner> [r/o]
								/** Returns owner widget. */
		SA_ObjectWithProperties*	get_Owner( void ) const;

		// <Type> [r/o]
								/** Returns type of the property value. */
		SA_ValueType			get_Type( void ) const;
		
		//	<Value> [r/w]
								/** Returns name of the property. */ 
		SA_Variant				get_Value( void ) const;
		void					set_Value( const SA_Variant& inValue );


	public://///////////////////////////////////////////////////////////////////////////

		//---------------------
		// Access to base:

		bool					ToBool( void ) const;
		long					ToLong( void ) const;
		String					ToString( void ) const;		
};


#endif // __Property
