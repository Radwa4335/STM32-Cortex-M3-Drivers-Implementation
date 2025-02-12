/*
 * CortexM3_Core_SysTick.h
 *
 *  Created on: Jan 29, 2024
 *      Author: radwa
 */

#ifndef CORTEXM3_CORE_SYSTICK_H_
#define CORTEXM3_CORE_SYSTICK_H_

/*--------------------------Includes Start--------------------------------------*/
#include "Std_Types.h"
#include "CortexM3_Core_SysTick_Cfg.h"
#include "Common_Macros.h"
#include "stddef.h"
/*--------------------------Includes End----------------------------------------*/
/*--------------------------Macro Declarations Start----------------------------*/
/* Memory mapping of Core Hardware*/
#define SysTick_BASE                (0xE000E010UL)
#define SysTick                     ((SysTick_Type *)SysTick_BASE)

/*SysTick Control / Status Register Definitions */
#define SysTick_CTRL_ENABLE_POS         0U
#define SysTick_CTRL_ENABLE_MSK         (1UL << SysTick_CTRL_ENABLE_POS)

#define SysTick_CTRL_TICKINT_POS        1U
#define SysTick_CTRL_TICKINT_MSK        (1UL << SysTick_CTRL_TICKINT_POS)

#define SysTick_CTRL_CLKSOURCE_POS      2U
#define SysTick_CTRL_CLKSOURCE_MSK      (1UL << SysTick_CTRL_CLKSOURCE_POS)

#define SysTick_CTRL_COUNTFLAG_POS      16U
#define SysTick_CTRL_COUNTFLAG_MSk      (1UL << SysTick_CTRL_COUNTFLAG_POS)

/*SysTick Reload Register Definitions*/
#define SysTick_LOAD_RELOAD_POS         0U
#define SysTick_LOAD_RELOAD_MSK         (0xFFFFFFUL << SysTick_LOAD_RELOAD_POS)           /* FFFFFF the maximum value that can be written in this register*/

#define SysTick_SingleInterval_Mode      0
#define SysTick_PeriodicInterval_Mode    1
/*--------------------------Macro Declarations End------------------------------*/
/*--------------------------Macro Functions Declarations Start------------------*/


/*--------------------------Macro Functions Declarations End--------------------*/
/*--------------------------Data Type Declarations Start------------------------*/
/**
 \brief Structure type to access the System Timer (SysTick)
 */
typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
} SysTick_Type;

typedef void (* ptrFunction)(void);
/*--------------------------Data Type Declarations End------------------------*/
/*--------------------------Software Interfaces Declarations Start------------*/
/**
 \brief System Tick Configuration
 \details Initializes the system timer and its interrupt, and disable the system tick timer.
 \return 0 Function Succeeded
 \return 1 Function Failed
 */
uint32_t SysTick_Init(uint32_t SysTick_Ticks);

void SysTick_DeInit(void);

void SysTick_WaitBlocking(uint32_t SysTick_Ticks);

uint32_t SysTick_GetRemainingTicks(void);

void SysTick_SingleInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack);

void SysTick_PeriodicInterval(uint32_t SysTick_Ticks, ptrFunction *CallBack);
/*--------------------------Software Interfaces Declarations End--------------*/


#endif /* CORTEXM3_CORE_SYSTICK_H_ */
