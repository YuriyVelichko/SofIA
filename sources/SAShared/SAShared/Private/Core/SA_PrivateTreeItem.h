/********************************************************************************************************/
/* SA_PrivateTreeItem.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_PrivateTreeItem
#define	__SA_PrivateTreeItem

// COMMON
#include <SAShared/Common/SA_String.h>

// CORE
#include <SAShared/Core/SA_ObjectWithProperties.h>

/********************************************************************************************************/
// Forward declaration
class SA_TreeItem;


/********************************************************************************************************/
class SAUI_API SA_PrivateTreeItem : public SA_ObjectWithProperties
{
	public://///////////////////////////////////////////////////////////////////////////

								SA_PrivateTreeItem( SA_TreeItem* inParemt );


	public://///////////////////////////////////////////////////////////////////////////

	


	protected://////////////////////////////////////////////////////////////////////////

		vector<SA_TreeItem*>	mChildren;

		SA_TreeItem*			mpParent;	
};

/**********************************************************************************************/
#endif //__SA_PrivateTreeItem
