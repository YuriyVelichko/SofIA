/********************************************************************************************************/
/* SA_Widget.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_Widget
#define	__SA_Widget

// STD
#include <memory>

// COMMON
#include <SAShared/Common/SA_String.h>

// CORE
#include <SAShared/Core/SA_TreeItem.h>
#include <SAShared/Core/SA_CoreConstants.h>

/********************************************************************************************************/
// This class is a base for all widgets, 
// that will be implemented in the plug-in's, for custom UI frameworks.
// Every object, that will represents a UI widget should be inherited from this class.
//
// This class implements base behavior:
// - provides possibility to create custom set of properties for widget;
// - provides easy way to create child-parent interaction between widgets.
//
class SAUI_API SA_Widget 
: 
	public SA_TreeItem
{
	public://///////////////////////////////////////////////////////////////////////////
						
								SA_Widget( SA_Widget* inParent );


	public://///////////////////////////////////////////////////////////////////////////

// WidgetWithProperties

	//---------------------
	// Methods:

virtual	void					CreateProperties	( void );								
virtual	void					UpdateAllProperties	( void );
virtual	void					UpdateProperty		( const String& inName );

	public://///////////////////////////////////////////////////////////////////////////

// This Class API

	//---------------------
	// Virtual Properties:

		// <WidgetType> [r/o]
								/** Returns type of the widget. */
virtual	SA_WidgetType			get_WidgetType( void ) const			{ return kWidget_Undefined; }

		// <WidgetTypeString> [r/o]
								/** Returns String value of the widget type. */
virtual	String					get_WidgetTypeString( void ) const		{ return String::Empty(); }


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:



	public://///////////////////////////////////////////////////////////////////////////
	
	//---------------------
	// Methods:

};

#endif //__SA_Widget
