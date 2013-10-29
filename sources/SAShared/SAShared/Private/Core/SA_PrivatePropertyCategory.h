/********************************************************************************************************/
/* PrivatePropertyCategory.h																			*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __PrivatePropertyCategory
#define	__PrivatePropertyCategory

// STD
#include <vector>

// COMMON
#include <SAShared/Common/SA_String.h>


/********************************************************************************************************/
// Forward declaration
class SA_ObjProperty;
class SA_ObjectWithProperties;


/********************************************************************************************************/
class SAUI_API SA_PrivatePropertyCategory
{
	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Properties:
		

	protected://////////////////////////////////////////////////////////////////////////
		
		SA_ObjectWithProperties*	mpOwner;

		String						mName;
		vector<SA_ObjProperty*>		mProperties;

		String						mDescription;
};


#endif // __PrivatePropertyCategory