/*
 ****************************************************************
 * @file	: STM32F103_HAL_NVIC.c
 * @author	: Radwa Waheed
 * @brief	: Contains the static code of the NVIC
 ****************************************************************
 */

#include "CortexM3_Core_NVIC.h"

void NVIC_EnableIRQ(IRQn_Type IRQn)
{
	 if ((uint32_t)IRQn >= 0){
		 NVIC->ISER[((uint32_t)IRQn) >> 5]= (1UL << ((uint32_t)IRQn & 0x1F));            // anded with 1f which is 31 in decimal to get the bit position that i want to set it. Then shit left the number 1 by the amount of the bit position to set the desired bit.
	 }
}
void NVIC_DisableIRQ(IRQn_Type IRQn)
{
	 if ((uint32_t)IRQn >= 0){
		NVIC->ICER[((uint32_t)IRQn) >> 5]= (1UL << ((uint32_t)IRQn & 0x1F));
	 }
}

void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0){
		NVIC->ISPR[((uint32_t)IRQn) >> 5]= (1UL << ((uint32_t)IRQn & 0x1F));
	}
}

void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0){
		NVIC->ICPR[((uint32_t)IRQn) >> 5]= (1UL << ((uint32_t)IRQn & 0x1F));
	}
}

uint8_t NVIC_GetActive(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0){
	return ((NVIC->IABR[((uint32_t)IRQn) >> 5]) & (1UL << ((uint32_t)IRQn & 0x1F))) != ((uint32_t)0) ? 1UL : 0UL;
	}
	else{
		return 0;
	}
}

void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
	 if ((uint32_t)IRQn >= 0){
			 NVIC->IP[((uint32_t)IRQn)]= (uint8_t)((priority << 4) & (uint32_t)0xFF);
	 }
	 else{
		 /* Nothing */
	 }
}

uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{
	if ((uint32_t)IRQn >= 0){
		return ((NVIC->IP[((uint32_t)IRQn)]) >> 4);
		 }
		 else{
			 /* Nothing */
		 }
}
