/********************************************************************************************************/
/* SA_TreeItem.h																						*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_TreeItem
#define	__SA_TreeItem

// COMMON
#include <SAShared/Common/SA_String.h>

// Private
#include <SAShared/Private/Core/SA_PrivateTreeItem.h>


/********************************************************************************************************/
class SAUI_API SA_TreeItem : public SA_PrivateTreeItem
{
	public://///////////////////////////////////////////////////////////////////////////

								SA_TreeItem( SA_TreeItem* inParent );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Virtual Methods:

								/** Returns copy of object.
								*	Should be overridden. */
virtual	SA_TreeItem*			Clone( SA_TreeItem* inParent )					{ return nullptr; }


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:
	


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

								/** Adds child.*/ 
		void					AddChild( SA_TreeItem* inChild );								
};

/**********************************************************************************************/
#endif //__SA_TreeItem
