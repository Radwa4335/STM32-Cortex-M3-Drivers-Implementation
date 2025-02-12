#ifndef HAL_DRIVERS_DMA_STM32F103_HAL_DMA_H_
#define HAL_DRIVERS_DMA_STM32F103_HAL_DMA_H_




/* ----------------- Includes Start ---------------------------- */
#include "Std_Types.h"
#include "Common_Macros.h"

#define PERIPH_BASE						0x40000000UL
/* DMA */
#define DMA_BASE_ADDRESS 				(PERIPH_BASE + 0x00020000UL)
#define DMA								((volatile DMA_t*) DMA_BASE_ADDRESS)


/* ----------------- Includes End ---------------------------- */

/* ----------------- Macro Declarations Start ---------------------------- */
/* ----------------- Macro Declarations End ---------------------------- */

/* ----------------- Macro Functions Declarations Start ---------------------------- */
/* ----------------- Macro Functions Declarations End ---------------------------- */

/* ----------------- Data Type Declarations Start---------------------------- */

/* * * * * * * * * * * * * * * *  DMA Registers Structure  * * * * * * * * * * * * * * * */
typedef struct{

	volatile uint32_t CCR       ;
	volatile uint32_t CNDTR     ;
	volatile uint32_t CPAR      ;
	volatile uint32_t CMAR      ;
	volatile uint32_t RESERVED  ;

}DMACHANNEL;

typedef struct{

	volatile uint32_t ISR       ;
	volatile uint32_t IFCR      ;
	DMACHANNEL CHANNEL[7]  ;

}DMA_t;


/**
 * @brief DMA Channel Number
 *
 */
typedef enum
{
    CHANNEL1 ,
    CHANNEL2 ,
    CHANNEL3 ,
    CHANNEL4 ,
    CHANNEL5 ,
    CHANNEL6 ,
    CHANNEL7
}DMA_Channel_t ;

typedef enum
{
    DMA_LOW     = 0 ,
    DMA_MEDIUM  = 0x1000 ,
    DMA_HIGH    = 0x2000,
    DMA_VERY_HIGH =0x8000
}DMA_Channelpriority_t ;

/**
 * @brief DMA Channel Cicular Mode
 *
 */
typedef enum
{
    DISABLE_CIRCULAR ,
    ENABLE_CIRCULAR = 0x20
}DMA_ChannelMode_t ;
/**
 * @brief DMA Transfer Direction
 *
 */
typedef enum
{
    MEM_TO_MEM  = (1<<14),
    PREI_TO_MEM = 0 ,
    MEM_TO_PERI = (1<<4)
}DMA_Direction_t ;

/**
 * @brief DMA Element size for one transfer
 *
 */
typedef enum
{
    BYTE    ,
    HALF_WORD ,
    WORD
}DMA_elementSize_t;

/**
 * @brief DMA Memory Incremnet
 *
 */
typedef enum
{
    MEM_INCREMENT_DISABLE ,
    MEM_INCREMENT_ENABLE = 0x80
}DMA_MemIncrement_t;

/**
 * @brief DMA Pripheral Incremnet
 *
 */
typedef enum
{
    PERIPHERAL_INCREMENT_DISABLE ,
    PERIPHERAL_INCREMENT_ENABLE =0x40
}DMA_PripheralIncrement_t ;

/**
 * @brief DMA Half Transfer Interrupt
 *
 */
typedef enum
{
    HALF_TX_INT_DISABLE ,
    HALF_TX_INT_ENABLE  = 0x4
}DMA_halfTxInterrupt_t ;


/**
 * @brief DMA Transfer Complete Interrupt
 *
 */

typedef enum
{
    TX_INT_DISABLE ,
    TX_INT_ENABLE = 0x2
}DMA_CompleteTxInterrupt_t;

typedef enum
{
    ERROR_INT_DISABLE ,
    ERROR_INT_ENABLE = 0x8
}DMA_errorInterrupt_t;

typedef enum
{
    CHANNEL_DISABLE ,
    CHANNEL_ENABLE

}DMA_State_t ;

typedef struct
{
    DMA_Channel_t                   channelNumber           ;
    DMA_Channelpriority_t           channelPriority         ;
    DMA_ChannelMode_t               channelCircularMode     ;
    DMA_Direction_t                 channelDirection        ;
    DMA_elementSize_t               channelMemElementSize  ;
    DMA_elementSize_t               channelPriphElementSize  ;
    DMA_MemIncrement_t              channelMemIncrement     ;
    DMA_PripheralIncrement_t        channelPriphIncremnet   ;
    DMA_halfTxInterrupt_t           channelHalfTransferInt  ;
    DMA_CompleteTxInterrupt_t       channelCompleteTransferInt  ;
    DMA_errorInterrupt_t            channelerrorInTransferInt   ;
}DMA_Config_t;


/*
typedef struct {
    volatile uint32_t ISR;
    volatile uint32_t IFCR;
    volatile uint32_t CCR1;
    volatile uint32_t CNDTR1;
    volatile uint32_t CPAR1;
    volatile uint32_t CMAR1;
    volatile uint32_t Reserved1[1];
    volatile uint32_t CCR2;
    volatile uint32_t CNDTR2;
    volatile uint32_t CPAR2;
    volatile uint32_t CMAR2;
    volatile uint32_t Reserved2[1];
    volatile uint32_t CCR3;
    volatile uint32_t CNDTR3;
    volatile uint32_t CPAR3;
    volatile uint32_t CMAR3;
    volatile uint32_t Reserved3[1];
    volatile uint32_t CCR4;
    volatile uint32_t CNDTR4;
    volatile uint32_t CPAR4;
    volatile uint32_t CMAR4;
    volatile uint32_t Reserved4[1];
    volatile uint32_t CCR5;
    volatile uint32_t CNDTR5;
    volatile uint32_t CPAR5;
    volatile uint32_t CMAR5;
    volatile uint32_t Reserved5[1];
    volatile uint32_t CCR6;
    volatile uint32_t CNDTR6;
    volatile uint32_t CPAR6;
    volatile uint32_t CMAR6;
    volatile uint32_t Reserved6[1];
    volatile uint32_t CCR7;
    volatile uint32_t CNDTR7;
    volatile uint32_t CPAR7;
    volatile uint32_t CMAR7;
    volatile uint32_t Reserved7[1];
} DMA_TypeDef;
*/

/* ----------------- Data Type Declarations End ---------------------------- */

/* ----------------- Software Interfaces Declarations Start ---------------------------- */

/**
 * @brief This Function is used to init DMA channel
 *
 * @param ptr_UsrConfig  @ref DMA_Config_t
 */
void DMA_voidInitChannel(DMA_Config_t* ptr_UsrConfig) ;

/**
 * @brief This Function is used to Enable/Disable DMA Channel
 *
 * @param channelNumber channel Number @ref DMA_Channel_t
 * @param channelState  channel state @ref DMA_State_t
 */
void DMA_voidSetChannelState(DMA_Channel_t channelNumber, DMA_State_t channelState);

/**
 * @brief This Function is used to Enable/Disable Half Interrupt Complete
 *
 * @param channelNumber channel Number @ref DMA_Channel_t
 * @param channelHalfTransferIntState interrupt state @ref DMA_halfTxInterrupt_t
 */
void DMA_voidSetHalfCompleteInterruptState(DMA_Channel_t channelNumber , DMA_halfTxInterrupt_t channelHalfTransferIntState);

/**
 * @brief This Function is used to Enable/Disable Interrupt Complete
 *
 * @param channelNumber channel Number @ref DMA_Channel_t
 * @param channelCompleteTransferInt interrupt state @ref DMA_CompleteTxInterrupt_t
 */
void DMA_voidSetCompleteInterruptState(DMA_Channel_t channelNumber , DMA_CompleteTxInterrupt_t channelCompleteTransferInt);


/**
 * @brief This Function is used to Enable/Disable Error Interrupt
 *
 * @param channelNumber channel Number @ref DMA_Channel_t
 * @param channelerrorInTransferInt interrupt state @ref DMA_errorInterrupt_t
 */
void DMA_voidSetErrorInterruptState(DMA_Channel_t channelNumber , DMA_errorInterrupt_t  channelerrorInTransferInt);



/**
 * @brief This Function is used to start transfer data this function enable dma directly
 *
 * @param channelNumber         channel Number @ref DMA_Channel_t
 * @param PeripheralAddress     Address of Pripheral/Mem
 * @param MemoryAddress         address of memory
 * @param Copy_u16BlockSize     number of data to be transfer
 * @param Ptr                   pointer to function when TX Complete
 */
void DMA_voidStartTransfer(DMA_Channel_t channelNumber , uint32_t * PeripheralAddress , uint32_t * MemoryAddress , uint16_t Copy_u16BlockSize ,  void ( *Ptr ) ( void ));

/* ----------------- Software Interfaces Declarations End ---------------------------- */

#endif /* HAL_DRIVERS_DMA_STM32F103_HAL_DMA_H_ */
