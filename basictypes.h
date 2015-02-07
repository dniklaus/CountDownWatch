/*
 * basictypes.h
 *
 *  Created on: 15.12.2011
 *      Author: dniklaus
 */

#ifndef BASICTYPES_H_
#define BASICTYPES_H_

/* address type */
typedef void*           BTAddress;

/* signed base types 8, 16, 32 bit */
typedef signed char     BTInt8;
typedef signed short    BTInt16;
typedef signed long     BTInt32;

/* unsigned base types 8, 16, 32 bit */
typedef unsigned char   BTUInt8;
typedef unsigned short  BTUInt16;
typedef unsigned long   BTUInt32;

/* bit-set base types 8, 16, 32 bit */
typedef unsigned char   BTBitset8;
typedef unsigned short  BTBitset16;
typedef unsigned long   BTBitset32;

/* boolean types 8, 16, 32 bit */
typedef int             BTBool;
typedef unsigned char   BTBool8;
typedef unsigned short  BTBool16;
typedef unsigned long   BTBool32;

/* char types */
typedef char            BTChar;
typedef unsigned char   BTUChar;


#define BTTRUE          1
#define BTFALSE         0

/* exception type */
typedef BTUInt32        BTXCode;
#define BTXSUCCESS      0
#define BTXERROR        0xFFFFFFFF

/* macro to test xcode for success              */
/* use     if ( BT_IS_SUCCESS(xcode) ) { ... }  */
/* or      if (!BT_IS_SUCCESS(xcode) ) { ... }  */
#define BT_IS_SUCCESS(X) ( BTXSUCCESS == (X) )

#endif /* BASICTYPES_H_ */
