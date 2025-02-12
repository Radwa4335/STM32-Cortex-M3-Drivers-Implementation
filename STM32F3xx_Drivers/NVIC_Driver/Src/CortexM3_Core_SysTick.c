/*
 ****************************************************************
 * @file	: STM32F103_HAL_SysTick.c
 * @author	: Radwa Waheed
 * @brief	: Contains the static code of the SysTick
 ****************************************************************
 */
#include "CortexM3_Core_SysTick.h"
static volatile ptrFunction SysTick_CallBack = NULL;
static volatile uint8_t SysTick_Mode = SysTick_SingleInterval_Mode;

uint32_t SysTick_Init(uint32_t SysTick_Ticks)  // this function returns Retval which can be 1 if the function fail or 0 if succeeded
{
	uint32_t RetVal =0;                       // Initialized to be 0 (function succeeded)
	if (SysTick_Ticks > SysTick_LOAD_RELOAD_MSK){
		RetVal =1;                            // function failed in case the user entered a systick_ticks greater than FFFFFF (maximum value of the reload register)
	}
	else{
		/*Disable SysTick Counter*/
		CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;
		/*Reset the SysTick Counter Value*/
		SysTick->VAL = 0;
		/* Select the Processor Clock*/
#if (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_1)
		SET_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_MSK);
#elif (SYSTICK_CLOCK_SOURCE == SYSTICK_CLOCK_SOURCE_DIV_8)
		CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_CLKSOURCE_MSK);
#else
#error "Invalid Clock Source"
#endif
		/*Disable SysTick IRQ (interrupt request )*/
		CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_MSK);
	}
	return RetVal;
}



void SysTick_DeInit(void)
{
	/*Disable SysTick Counter*/
	CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
	/*Set Reload Register to SysTick_Ticks*/
	SysTick->LOAD = 0;
	/*Reset the SysTick Counter Value*/
	SysTick->VAL = 0;
	/*Disable SysTick IRQ*/
	CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_MSK);
}


void SysTick_WaitBlocking(uint32_t SysTick_Ticks) // delay function
{
	/*Set Reload Register to SysTick_Ticks*/
	SysTick->LOAD = SysTick_Ticks;
	/*Enable SysTick Counter*/
	SET_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
	/*Wait the COUNTFLAG Return 1 (by default the counter flag bit is 0 and returns 1 when the counter reaches 0)*/
	while(READ_BIT(SysTick->CTRL, SysTick_CTRL_COUNTFLAG_MSk) == 0);
	/*Disable SysTick counter*/
	CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
	/*Reset the SysTick Reload Register*/
	SysTick->LOAD = 0;
	/*Reset the SysTick counter value*/
	SysTick->VAL = 0;
}

uint32_t SysTick_GetRemainingTicks(void)
{
	uint32_t RemainingTicks =0;
	/*Copy The SysTick counter register to a local variable*/
	RemainingTicks= SysTick->VAL;
	/*Return the local variable*/
	return RemainingTicks;
}

void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack)
{
	if(CallBack != NULL){
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;
		/* Copy the user callback to a local ptrFunction */
		SysTick_CallBack = CallBack;
		/* Set SysTick timer to the single interval mode */
		SysTick_Mode = SysTick_SingleInterval_Mode;
		/*Enable SysTick IRQ NVIC Line*/
		SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_MSK);
		/* Enable SysTick timer to asserts the SysTick exception request */
		SET_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
	}
	else{ /*Nothing*/ }
}
void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack)
{
	if(CallBack != NULL){
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = SysTick_Ticks;
		/* Copy the user callback to a local ptrFunction */
		SysTick_CallBack = CallBack;
		/* Set SysTick timer to the periodic interval mode */
		SysTick_Mode = SysTick_PeriodicInterval_Mode;
		/*Enable SysTick IRQ NVIC Line*/
		SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_MSK);
		/*Enable SysTick Counter*/
		SET_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
	}
	else{ /*Nothing*/ }

}
void SysTick_Handler(void){
	/* In case of using single interval*/
	if(SysTick_Mode == SysTick_SingleInterval_Mode){
		/*Disable SysTick Counter*/
		CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_ENABLE_MSK);
		/*Set Reload Register to SysTick_Ticks*/
		SysTick->LOAD = 0;
		/*Reset the SysTick Counter Value*/
		SysTick->VAL = 0;
		/*Disable SysTick IRQ*/
		CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_MSK);
	}

	if(SysTick_CallBack){
		SysTick_CallBack();
	}
}
