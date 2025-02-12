/*
 * BIT_MATH.h
 *
 *  Created on: Feb 19, 2024
 *      Author: radwa
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT)					VAR |= (1 << (BIT))
#define CLR_BIT(VAR,BIT) 					VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)                    ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)                     VAR ^=  (1 << (BIT))
#define SPECIAL_SET(VAR,SHIFTNUM, BIT)		VAR |= (SHIFTNUM << (BIT))
#define SPECIAL_CLR(VAR,SHIFTNUM, BIT)		VAR &= ~(SHIFTNUM << (BIT))
#define NULL (void *)0

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))
#define READ_REG(REG)         ((REG))

#endif /* BIT_MATH_H_ */
