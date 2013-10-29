/********************************************************************************************************/
/* WidgetWithProperties.h																				*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __WidgetWithProperties
#define	__WidgetWithProperties

// STD
#include <vector>

// SHARED 
#include <Shared/Core/SA_PropertyCategory.h>
#include <Shared/Core/SA_Property.h>
#include <Shared/Core/SA_Variant.h>


/********************************************************************************************************/
class SAUI_API SA_ObjectWithProperties 
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:

		// <Properties> [r/o]

								/** Returns all properties of the object. */
const vector<SA_ObjProperty*>&	get_Properties( void ) const;
		
		// <Property>
								/** Returns property with given name.
								/*	If property with same name does not presents in the object
								/*	returns empty property.	*/
		SA_ObjProperty*			get_Property( const String& inName ) const;

		void					set_Property( 
									const String&		inName, 
									SA_Variant			inVariant );

		// <PropertyCount> [r/o]
								/** Returns number of properties. */
		size_t					get_PropertyCount( void ) const;

		// <Category>
								/** Returns category with given name.
								/*	If category with same name does not presents in the object
								/*	returns NULL.	*/
		SA_ObjProperty*			get_Category( const String& inName ) const;

		// <CategoryCount> [r/o]
								/** Returns number of categories. */
		size_t					get_CategoryCount( void ) const;


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Virtual methods:		

								/** Create properties of the widget. */
virtual	void					CreateProperties( void )				{}							

								/** Updates all properties of widget. */
virtual	void					UpdateAllProperties( void )				{}

								/** Updates property of the widget. */
virtual	void					UpdateProperty( const String& inName )	{}


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Access To Data:

		bool					GetBool	( const String& inPropName ) const;
		long					GetLong	( const String& inPropName ) const;
		String					GetString( const String& inPropName ) const;   	


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

								/** Adds new category. 
								/*	If category with same name already exists - returns that category. */
		SA_PropertyCategory*	AddCategory( const String& inName );

								/** Adds new property to the current category. 
								/*	If property with same name already exists - returns that property. */
		SA_ObjProperty*			AddProperty( 
									const String&		inName, 
									const SA_Variant&	inValue );
										
								/** Returns empty property. */
		SA_ObjProperty*			GetEmptyProperty( void ) const;

								/** Returns TRUE if exits property with same name. */
		bool					HasProperty( const String& inName ) const;


	protected:///////////////////////////////////////////////////////////////////////////

		vector<SA_PropertyCategory*>	mCategories;
		vector<SA_ObjProperty*>			mProperties;
};


#endif // __WidgetWithProperties
