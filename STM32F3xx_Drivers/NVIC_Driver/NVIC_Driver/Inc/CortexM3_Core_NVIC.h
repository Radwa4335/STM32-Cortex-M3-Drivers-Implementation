/*
 * CortexM3_Core_NVIC.h
 *
 *  Created on: Jan 28, 2024
 *      Author: radwa
 */

#ifndef CORTEXM3_CORE_NVIC_H_
#define CORTEXM3_CORE_NVIC_H_

/* ------------------------ Includes Start ---------------------------------- */
#include "Std_Types.h"
/* ------------------------ Includes End ------------------------------------ */
/* ------------------------ Macro Declarations Start ------------------------ */
#define NVIC_BASE         (0xE000E100UL)
#define NVIC              ((NVIC_Type *)NVIC_BASE)
/* ------------------------ Macro Declarations End -------------------------- */
/* ------------------------ Data Type Declarations Start -------------------- */
/**
  \brief structure type to access the nested vector interrupt controller (NVIC).
*/
typedef struct
{
  volatile uint32_t ISER[8U];
  uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];
  uint32_t RESERVED1[24U];
  volatile uint32_t ISPR[8U];
  uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];
  uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];
  uint32_t RESERVED4[56U];
  volatile uint8_t IP[240U];
  uint32_t RESERVED5[644U];
  volatile uint32_t STIR;
} NVIC_Type;

typedef enum
{
  Nonmaskableinterrupt_IRQn      = -14,
  Memorymanagement_IRQn          = -12,
  BusFault_IRQn                  = -11,
  UsageFault_IRQn                = -10,
  SVCall_IRQn                    = -5,
  DebugMonitor_IRQn              = -4,
  PendSV_IRQn                    = -2,
  SysTick_IRQn                   = -1,
  WWDG_IRQn                      = 0,
  PVD_IRQn                       = 1,
  TAMPER_IRQn                    = 2,
  RTC_IRQn                       = 3,
  FLASH_IRQn                     = 4,
  RCC_IRQn                       = 5,
  EXTI0_IRQn                     = 6,
  EXTI1_IRQn                     = 7,
  EXTI2_IRQn                     = 8,
  EXTI3_IRQn                     = 9,
  EXTI4_IRQn                     = 10,
  DMA1_Channel1_IRQn             = 11,
  DMA1_Channel2_IRQn             = 12,
  DMA1_Channel3_IRQn             = 13,
  DMA1_Channel4_IRQn             = 14,
  DMA1_Channel5_IRQn             = 15,
  DMA1_Channel6_IRQn             = 16,
  DMA1_Channel7_IRQn             = 17,
  ADC1_2_IRQn                    = 18,
  USB_HP_CAN_TX_IRQn             = 19,
  USB_LP_CAN_RX0_IRQn    		 = 20,
  CAN_RX1_IRQn           		 = 21,
  CAN_SCE_IRQn           		 = 22,
  EXTI9_5_IRQn      		     = 23,
  TIM1_BRK_IRQn        			 = 24,
  TIM1_UP_IRQn           		 = 25,
  TIM1_TRG_COM_IRQn      		 = 26,
  TIM1_CC_IRQn           		 = 27,
  TIM2_IRQn              		 = 28,
  TIM3_IRQn              		 = 29,
  TIM4_IRQn              		 = 30,
  I2C1_EV_IRQn           		 = 31,
  I2C1_ER_IRQn           		 = 32,
  I2C2_EV_IRQn           		 = 33,
  I2C2_ER_IRQn           		 = 34,
  SPI1_IRQn              		 = 35,
  SPI2_IRQn              		 = 36,
  USART1_IRQn            		 = 37,
  USART2_IRQn            		 = 38,
  USART3_IRQn                    = 39,
  EXTI15_10_IRQn                 = 40,
  RTCAlarm_IRQn                  = 41,
  USBWakeup_IRQn                 = 42,
  TIM8_BRK_IRQn                  = 43,
  TIM8_UP_IRQn                   = 44,
  TIM8_TRG_COM_IRQn              = 45,
  TIM8_CC_IRQn                   = 46,
  ADC3_IRQn                      = 47,
  FSMC_IRQn                      = 48,
  SDIO_IRQn                      = 49,
  TIM5_IRQn                      = 50,
  SPI3_IRQn                      = 51,
  UART4_IRQn                     = 52,
  UART5_IRQn                     = 53,
  TIM6_IRQn                      = 54,
  TIM7_IRQn                      = 55,
  DMA2_Channel1_IRQn             = 56,
  DMA2_Channel2_IRQn             = 57,
  DMA2_Channel3_IRQn             = 58,
  DMA2_Channel4_5_IRQn           = 59,
}IRQn_Type;
/* ------------------------ Data Type Declarations End ---------------------- */
/* ------------------------ Software Interfaces Declarations Start ---------- */
void NVIC_EnableIRQ(IRQn_Type IRQn);  // IRQn takes one of the enumerators, does not return anything
void NVIC_DisableIRQ(IRQn_Type IRQn);
void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint8_t NVIC_GetActive(IRQn_Type IRQn);   //returns high or low
void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
uint32_t NVIC_GetPriority(IRQn_Type IRQn);
/* ------------------------ Software Interfaces Declarations End ------------ */

#endif /* CORTEXM3_CORE_NVIC_H_ */
