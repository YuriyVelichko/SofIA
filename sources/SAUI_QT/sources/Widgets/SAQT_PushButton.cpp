/********************************************************************************************************/
/* SAQT_PushButton.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// Visual
#include <SAUI_QT/Widgets/SAQT_PushButton.h>

//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SAQT_PushButton::SAQT_PushButton( SA_TreeItem* inParent )
	:
SA_TreeItem( inParent )
{

}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark SA_TreeItem
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SA_TreeItem* SAQT_PushButton::Clone( SA_TreeItem* inParent )
{
	SAQT_PushButton* res = new SAQT_PushButton( inParent );

	// TODO: copy properties

	return res;
}