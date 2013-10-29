/********************************************************************************************************/
/* PropertyCategory.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __PropertyCategory
#define	__PropertyCategory

// COMMON
#include <Shared/Common/SA_String.h>

// CORE
#include <Shared/Private/Core/SA_PrivatePropertyCategory.h>


/********************************************************************************************************/
// Forward declaration
class SA_ObjectWithProperties;


/********************************************************************************************************/
class SAUI_API SA_PropertyCategory : public SA_PrivatePropertyCategory
{
	public://///////////////////////////////////////////////////////////////////////////

									SA_PropertyCategory( 
										SA_ObjectWithProperties*	inOwner,
										const String&				inName = String::Empty(),
										const String&				inDescription = String::Empty() );
								

	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:

		// <Description> [r/w]
									/** Returns description of the category. */
		String						get_Description( void ) const;
		void						set_Description( const String& inValue );

		//	<Name> [r/w]
									/** Returns name of the category. */ 
		String						get_Name( void ) const;
		void						set_Name( const String& inName );

		// <Owner> [r/o]
									/** Returns owner widget. */
		SA_ObjectWithProperties*	get_Owner( void ) const;

		// <Properties> [r/o]
									/** Returns set of properties of current category. */
const	vector<SA_ObjProperty*>&	get_Properties( void ) const;

};


#endif // __PropertyCategory