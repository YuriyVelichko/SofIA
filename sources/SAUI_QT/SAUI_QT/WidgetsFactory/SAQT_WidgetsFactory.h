/********************************************************************************************************/
/* SAQT_WidgetsFactory.h																				*/
/*																										*/
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SAQT_WidgetsFactory
#define __SAQT_WidgetsFactory

// SAUI_QT
#include <SAUI_QT/SAQT.h>

// STD
#include <map>

// Shared
#include <Shared/Core/SA_TreeItem.h>


/********************************************************************************************************/
class SAUI_API SAQT_WidgetsFactory
{	
	private:////////////////////////////////////////////////////////////////////////////

								SAQT_WidgetsFactory( void );


	public://///////////////////////////////////////////////////////////////////////////

// This Class API

	//---------------------
	// Static Methods:	

static	SAQT_WidgetsFactory*	Instance( void );


	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Static Methods:	

		SA_TreeItem*			CreateWidget( 
									size_t			inWidgetType,
									SA_TreeItem*	inParent		= nullptr );


	protected://////////////////////////////////////////////////////////////////////////

static	SAQT_WidgetsFactory*			mpFactory;

		std::map<size_t, SA_TreeItem*>	mObjects;
};


#endif // __SAQT_WidgetsFactory