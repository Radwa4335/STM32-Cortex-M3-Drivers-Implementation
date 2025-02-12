/*
 * FPEC.c
 *
 *  Created on: Feb 19, 2024
 *      Author: radwa
 */


/* ------------------------ Includes Start ---------------------------------- */
#include "Std_Types.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
#include "FPEC_config.h"
#include "FPEC_private.h"
/* ------------------------ Includes End ------------------------------------ */

/* --------------------- Module Preprocessor Constants Start ---------------- */
#define FLASH_KEY1               ((uint32_t)0x45670123)
#define FLASH_KEY2               ((uint32_t)0xCDEF89AB)
#define FPEC_WAIT_BUSY_FLAG()      while (GET_BIT(FPEC->SR,0) == 1)
#define FPEC_PAGE_SIZE             PAGE_SIZE_IN_K * (uint16_t)1024
/* -------------------- Module Preprocessor Constants End --------------------- */

static void FPEC_voidFlashUnlock(void)
{
    FPEC -> KEYR = FLASH_KEY1;
    FPEC -> KEYR = FLASH_KEY2;
}

void FPEC_voidInit(void)
{

}

void FPEC_voidFlashWrite(uint32_t Copy_u32Address, uint16_t* Ptr_u16Data, uint8_t Copy_u8Length)
{
	uint16_t LOC_u16Counter = 0 ;
    /*  Wait Busy Flag  */
    FPEC_WAIT_BUSY_FLAG();
    /*  Check Locking */
    if(GET_BIT(FPEC->CR,7) == 1)   // bit number 7 is the lock bit
    {
        // Unlock
        FPEC_voidFlashUnlock();
    }
    /*  Start Writing   */
    for(LOC_u16Counter = 0 ; LOC_u16Counter < Copy_u8Length ; LOC_u16Counter++)\
    {
        /* Write Flash Operation */
        SET_BIT(FPEC->CR,0);      // Flash programming chosen
        /* Half word operation (Just Ignore High Part Bec it Constnt 0x0800 xxxx) */
        *((volatile uint16_t*)Copy_u32Address) = Ptr_u16Data[LOC_u16Counter] ;
        /*  Increase Address by two byte    */
        Copy_u32Address = Copy_u32Address + 2 ;
        /*  Wait Busy Flag  */
        FPEC_WAIT_BUSY_FLAG();
        /* END of Programming   */
        SET_BIT(FPEC->SR,5);  // EOP, End of operation
		CLR_BIT(FPEC->CR,0);
    }
}

void FPEC_voidFlashWriteHalfWord(uint32_t Copy_u32Address, uint16_t Copy_u16Data)
{
    /*  Wait Busy Flag  */
    FPEC_WAIT_BUSY_FLAG();
    /*  Check Locking */
    if(GET_BIT(FPEC->CR,7) == 1)
    {
        // Unlock
        FPEC_voidFlashUnlock();
    }
    /*  Start Writing   */
    /* Write Flash Operation */
    SET_BIT(FPEC->CR,0);
    /* Half word operation (Just Ignore High Part Bec it Constnt 0x0800 xxxx) */
    *((volatile uint16_t*)Copy_u32Address) = Copy_u16Data ;
    /*  Increase Address by two byte    */
    Copy_u32Address = Copy_u32Address + 2 ;
    /*  Wait Busy Flag  */
    FPEC_WAIT_BUSY_FLAG();
    /* END of Programming   */
    SET_BIT(FPEC->SR,5);
    CLR_BIT(FPEC->CR,0);
}

void FPEC_voidFlashPageErase(uint8_t Copy_u8PageNumber)
{
    /*  Wait Busy Flag  */
    FPEC_WAIT_BUSY_FLAG();
    /*  Check Locking */
    if(GET_BIT(FPEC->CR,7) == 1)
    {
        // Unlock
        FPEC_voidFlashUnlock();
    }
    /* Page Erase Operation */
	SET_BIT(FPEC->CR,1);
    // Program the FLASH_AR register to select a page to erase.
   FPEC->AR = FLASH_START_ADDRESS + (uint32_t)(Copy_u8PageNumber * FPEC_PAGE_SIZE);
   	/* Start operation */
	SET_BIT(FPEC->CR,6);
    /*  Wait Busy Flag  */
    FPEC_WAIT_BUSY_FLAG();
	/* EOP */
	SET_BIT(FPEC->SR,5);
	CLR_BIT(FPEC->CR,1);

}


void FPEC_voidEraseAppArea(uint8_t Copy_u8StartFromPageNumber)
{
	uint16_t LOC_u16Counter = 0 ;
    for(LOC_u16Counter = Copy_u8StartFromPageNumber ; LOC_u16Counter < FLASH_SIZE_IN_K ; LOC_u16Counter++)
    {
        FPEC_voidFlashPageErase(LOC_u16Counter) ;
    }
}
