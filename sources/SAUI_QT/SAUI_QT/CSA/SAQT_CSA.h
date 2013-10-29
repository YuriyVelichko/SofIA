/********************************************************************************************************/
/* SAQT_CSA.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAQT_CSA
#define	__SAQT_CSA

// SAUI QT
#include <SAUI_QT/SAQT.h>

// SHARED
#include <Shared/Core/SA_TreeItem.h>


/********************************************************************************************************/
class SAUI_API SAQT_CSA : public SA_TreeItem 
{
	public://///////////////////////////////////////////////////////////////////////////

								SAQT_CSA( SA_TreeItem* inParent );

	public://///////////////////////////////////////////////////////////////////////////

// SA_TreeItem

	//---------------------
	// Methods:

		SA_TreeItem*			Clone( SA_TreeItem* inParent );
};


#endif // __SAQT_CSA