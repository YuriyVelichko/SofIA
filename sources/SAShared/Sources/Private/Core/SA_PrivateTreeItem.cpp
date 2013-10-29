/********************************************************************************************************/
/* SA_PrivateTreeItem.cpp																				*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <StdAfx.h>

// PRIVATE
#include <SAShared/Private/Core/SA_PrivateTreeItem.h>

// CORE
#include <SAShared/Core/SA_TreeItem.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_PrivateTreeItem::SA_PrivateTreeItem( SA_TreeItem* inParent )
:
	mpParent( nullptr )
{
	mpParent = inParent;

	if( mpParent )
		mpParent->AddChild( static_cast<SA_TreeItem*>( this ) );
}