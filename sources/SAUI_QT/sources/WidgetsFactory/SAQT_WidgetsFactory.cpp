/********************************************************************************************************/
/* KA_KernelFactory.h                                                                                   */
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

// SAUI_QT
#include <SAUI_QT/CSA/SAQT_CSA.h>
#include <SAUI_QT/WidgetsFactory/SAQT_WidgetsFactory.h>
#include <SAUI_QT/Widgets/SAQT_PushButton.h>


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Construction Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SAQT_WidgetsFactory* SAQT_WidgetsFactory::mpFactory = nullptr;


/********************************************************************************************************/
SAQT_WidgetsFactory::SAQT_WidgetsFactory( void )
{

}


//////////////////////////////////////////////////////////////////////
#pragma mark -
#pragma mark Static Methods
//////////////////////////////////////////////////////////////////////


/********************************************************************************************************/
SAQT_WidgetsFactory* SAQT_WidgetsFactory::Instance( void )
{
	if( !mpFactory )
		mpFactory = new SAQT_WidgetsFactory;

	return mpFactory;
}

/********************************************************************************************************/
SA_TreeItem* SAQT_WidgetsFactory::CreateWidget( 
	size_t			inWidgetType,
	SA_TreeItem*	inParent )
{
	SA_TreeItem* res = nullptr;

	if( mObjects.find( inWidgetType ) != mObjects.end() )
		res = mObjects.find( inWidgetType )->second->Clone( inParent );
	else
	{
		switch( inWidgetType )
		{			
			case kWidget_CSA		: res = new SAQT_CSA		( inParent );		break;
			case kWidget_PushButton	: res = new SAQT_PushButton	( inParent );		break;

			default: break;
		}

		mObjects[ inWidgetType ] = res;
	}

	return res;
}