/********************************************************************************************************/
/* SAQT_PushButton.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAQT_PushButton
#define	__SAQT_PushButton

// SAUI QT
#include <SAUI_QT/SAQT.h>

// SHARED
#include <Shared/Core/SA_TreeItem.h>


/********************************************************************************************************/
class SAUI_API SAQT_PushButton : public SA_TreeItem 
{
	public://///////////////////////////////////////////////////////////////////////////

								SAQT_PushButton( SA_TreeItem* inParent );


	public://///////////////////////////////////////////////////////////////////////////

// SA_TreeItem

		//---------------------
		// Methods:

		SA_TreeItem*			Clone( SA_TreeItem* inParent );

};


#endif // __SAQT_PushButton