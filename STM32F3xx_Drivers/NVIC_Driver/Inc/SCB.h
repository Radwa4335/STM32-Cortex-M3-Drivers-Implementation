#ifndef SCB_H_
#define SCB_H_

/* ------------------------ Includes Start ---------------------------------- */
#include "Std_Types.h"
/* ------------------------ Includes End ------------------------------------ */
/* ------------------------ Macro Declarations Start ------------------------ */
#define SCB_BASE     (0xE000ED00UL)
#define SCB          ((SCB_Type *)SCB_BASE)

#define SCB_PRIORITYGROUP_0          0x00000007U  // 1 group priority and 16 sub group priority (disabling nesting)
#define SCB_PRIORITYGROUP_1          0x00000006U
#define SCB_PRIORITYGROUP_2          0x00000005U
#define SCB_PRIORITYGROUP_3          0x00000004U
#define SCB_PRIORITYGROUP_4          0x00000003U

#define SCB_AIRCR_PRIGROUP_POS           8U   // SCB AIRCR: PRIGROUP POSITION
#define SCB_AIRCR_PRIGROUP_Msk           (7UL << SCB_AIRCR_PRIGROUP_POS)

#define SCB_AIRCR_VECTKEYSTAT_POS        16U  // SCB AIRCR: VETKEYSTAT POSITION
#define SCB_AIRCR_VECTKEYSTAT_Msk        (0xFFFFUL << SCB_AIRCR_VECTKEYSTAT_POS)
/* ------------------------ Macro Declarations END ---------------------------- */
/*--------------------------Data Type Declarations Start------------------------*/
/**
 \brief Structure type to access the System Control Block (SCB)
 */
typedef struct
{
	volatile uint32_t CPUID;
	volatile uint32_t ICSR;
	volatile uint32_t VTOT;
	volatile uint32_t AIRCR;
	volatile uint32_t SCR;
	volatile uint32_t CCR;
	volatile uint32_t SHPR1;
	volatile uint32_t SHPR2;
	volatile uint32_t SHPR3;
	volatile uint32_t SHCSR;
	volatile uint32_t CFSR;
} SCB_Type;
/*--------------------------Data Type Declarations End------------------------*/
/* ------------------------ Software Interfaces Declarations Start ---------- */
void SCB_SetPriorityGrouping(uint32_t priorityGroup);
uint32_t SCB_GetPriorityGrouping(void);
/* ------------------------ Software Interfaces Declarations End ------------ */


#endif /* SCB_H_ */
