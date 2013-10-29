/********************************************************************************************************/
/* SA_PrivateVariant.h																					*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __PrivateVariant
#define	__PrivateVariant

// STD
#include <memory>

// COMMON
#include <SAShared/Common/SA_String.h>

// CORE
#include <SAShared/Core/SA_CoreConstants.h>


/********************************************************************************************************/
struct SA_VariantData 
{
	union
	{
		bool			mBool;
		double			mDouble;
		long			mLong;
	};

	union
	{
		void*			mpPtr;
	};	
	
	String				mString;

	SA_ValueType		mType;
};


/********************************************************************************************************/
class SA_PrivateVariant
{
	protected://////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

	void								Init( SA_ValueType inType );

																		
	protected://////////////////////////////////////////////////////////////////////////
									
	std::shared_ptr<SA_VariantData>		mpData;
};

#endif //__PrivateVariant
