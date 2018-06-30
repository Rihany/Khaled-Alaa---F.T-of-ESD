/*
 * service.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: khaled
 */

#ifndef FILE_H_SERVICE_H_
#define FILE_H_SERVICE_H_


#define READ_BIT(REG,BIT) ((REG>>BIT)&1)
#define TOGGOL_BIT(REG,BIT) REG ^=(1<<BIT)

#define  SET_BIT(REG,BIT)   ((REG)|=(1<< BIT))
#define  CLEAR_BIT(REG,BIT)  ((REG)&=(char)~(1<< BIT))
#define  IS_BIT_SET(REG,BIT)  ((REG)&(1<<BIT))
#define  IS_BIT_CLEAR(REG,BIT)          (!((REG)&(1<<BIT)))

#endif /* FILE_H_SERVICE_H_ */
