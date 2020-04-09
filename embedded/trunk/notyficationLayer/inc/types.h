/*
 * types.h
 *
 *  Created on: 12 kwi 2019
 *      Author: amiar
 */

#ifndef INC_TYPES_H_
#define INC_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#define TRUE  (1)
#define FALSE (0)

#define SUCCESS int8(0)
#define FAIL    int8(-1)

typedef unsigned long uint64;
typedef long int64;
typedef unsigned int uint32;
typedef int int32;
typedef short int16;
typedef unsigned short uint16;
typedef unsigned char uint8;
typedef char int8;

#ifdef __cplusplus
}
#endif

#endif /* INC_TYPES_H_ */
