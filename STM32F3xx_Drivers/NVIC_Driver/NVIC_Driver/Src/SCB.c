/*
 * SCB.c
 *      Author: radwa
 */

#include "SCB.h"

void SCB_SetPriorityGrouping(uint32_t PriorityGroup)
{
	 uint32_t  Register_Value = 0;
	 uint32_t PriorityGroupTemp = ((uint32_t)PriorityGroup & (uint32_t)0x07);  // to ensure reading only the desired three bits and to clear the rest of the do not care bits
	 Register_Value = SCB ->AIRCR; // before writing in the register we read it
	 Register_Value &= ~(SCB_AIRCR_PRIGROUP_Msk | SCB_AIRCR_VECTKEYSTAT_Msk); // clear the desired locations and leave the rest as thery are
	 Register_Value = (Register_Value |
			          ((uint32_t)0x05FA << SCB_AIRCR_VECTKEYSTAT_POS) |
			          (PriorityGroupTemp << SCB_AIRCR_PRIGROUP_POS));
	 SCB ->AIRCR = Register_Value;
}

uint32_t SCB_GetPriorityGrouping(void)
{
	return (((uint32_t)SCB ->AIRCR & (uint32_t)SCB_AIRCR_PRIGROUP_Msk)>> SCB_AIRCR_PRIGROUP_POS);
}
