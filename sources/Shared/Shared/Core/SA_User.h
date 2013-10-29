/********************************************************************************************************/
/* SA_User.h																							*/
/*                                                                                                      */
/* Copyright Yuriy Velichko, 2011                                                                       */
/*                                                                                                      */
/********************************************************************************************************/

#ifndef __SA_User
#define	__SA_User

// SHARED
#include <Shared/Common/SA_String.h>

// CORE
#include <Shared/Core/SA_ObjectWithProperties.h>


/********************************************************************************************************/
// This class represents user model. 
// It will be init when creates a client connection to the kernel. 
// Each Client will associates with one user model.
// Later, to adapt UI, kernel will used this model, instead database.
//
// Kernel should  have possibilities to update  model, and change database record for user, using this class.
//
// This class has not possibilities to read or write data to the database. It's just a data storage.
//
class SAUI_API SA_User 	: public SA_ObjectWithProperties
{
	public://///////////////////////////////////////////////////////////////////////////

								SA_User( void );


	public://///////////////////////////////////////////////////////////////////////////

// ObjectWithProperties API

	//---------------------
	// Methods:

virtual	void					CreateProperties	( void );								
virtual	void					UpdateAllProperties	( void );
virtual	void					UpdateProperty		( const String& inName );


	public://///////////////////////////////////////////////////////////////////////////

// This class API

	//---------------------
	// Properties:

		void					InitProperties( const vector<SA_ObjProperty*>& inProerties );



	public://///////////////////////////////////////////////////////////////////////////

	//---------------------
	// Methods:

};

#endif //__SA_User