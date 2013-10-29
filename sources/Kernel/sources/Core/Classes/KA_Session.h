/********************************************************************************************************/
/* KA_Session.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __KA_Session
#define	__KA_Session

// KERNEL
#include <Interfaces/I_Session.h>

/********************************************************************************************************/
// Forward declaration
class KA_Kernel;


/********************************************************************************************************/
class KA_Session : public I_Session
{
	public:///////////////////////////////////////////////////////////////////////////

								KA_Session( KA_Kernel* inKernel );


	public:///////////////////////////////////////////////////////////////////////////

// I_Session API


	public:///////////////////////////////////////////////////////////////////////////
		
	//---------------------
	// Methods:	

		SA_ObjProperty*			GetKernelProperty( const String& inName ) const;
		SA_User*				GetUserModel( const SA_InitSessionData& inData ) const;


	public:///////////////////////////////////////////////////////////////////////////

// This Class API

		//---------------------
		// Properties:	



	public:///////////////////////////////////////////////////////////////////////////

		//---------------------
		// Methods:	

	protected:////////////////////////////////////////////////////////////////////////

		KA_Kernel*				mpKernel;

};


#endif // __KA_Session
