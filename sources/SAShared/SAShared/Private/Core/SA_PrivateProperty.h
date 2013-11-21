/********************************************************************************************************/
/* PrivateProperty.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __PrivateProperty
#define	__PrivateProperty

// COMMON
#include <SAShared/Common/SA_String.h>
#include <SAShared/Core/SA_Variant.h>


/********************************************************************************************************/
// Forward declarations
class SA_PropertyCategory;
class SA_ObjectWithProperties;


/********************************************************************************************************/
class SAUI_API SA_PrivateProperty
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:



	protected://////////////////////////////////////////////////////////////////////////
									
		String						mName;
		SA_Variant					mValue;

		String						mDescription;
		SA_ValueType				mType;

		SA_PropertyCategory*		mpCategory;
		SA_ObjectWithProperties*	mpOwner;
};


/**********************************************************************************************/
#endif // __PrivateProperty
