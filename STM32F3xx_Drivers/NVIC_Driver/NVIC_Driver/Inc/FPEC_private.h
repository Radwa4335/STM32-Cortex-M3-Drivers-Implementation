/*
 * PEC_private.h
 *
 *  Created on: Feb 19, 2024
 *      Author: radwa
 */

#ifndef FPEC_PRIVATE_H_
#define FPEC_PRIVATE_H_


/* ------------------------ Macro Declarations Start ------------------------ */
#define FPEC ((FPEC_TYPE*)0x40022000)
/* ------------------------ Macro Declarations End -------------------------- */


/* ------------------------ Data Type Declarations Start -------------------- */
typedef struct
{
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;
	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t RESERVED;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
}FPEC_TYPE;
/* ------------------------ Data Type Declarations End ---------------------- */

#endif /* FPEC_PRIVATE_H_ */
