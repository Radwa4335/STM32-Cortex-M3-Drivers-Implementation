#ifndef FPEC_INTERFACE_H_
#define FPEC_INTERFACE_H_

/**
 * @brief This Function is used to initialize FPEC Driver Module
 *
 */
void FPEC_voidInit(void);
/**
 * @brief This Function is used to Erase piece of code from page number @ref Copy_u8StartFromPageNumber to the end of the flash
 *
 * @param Copy_u8StartFromPageNumber Page number to start earase from it.
 */
void FPEC_voidEraseAppArea(uint8_t Copy_u8StartFromPageNumber);

/**
 * @brief This Function is used to erase specific page in flash.
 *
 * @param Copy_u8PageNumber pageNumber
 */
void FPEC_voidFlashPageErase(uint8_t Copy_u8PageNumber);

/**
 * @brief This Function is used to Write data on specific address with specific length.
 *
 * @param Copy_u32Address address of location to be written.
 * @param Ptr_u16Data    data to be written
 * @param Copy_u8Length   length of data
 */
void FPEC_voidFlashWrite(uint32_t Copy_u32Address, uint16_t* Ptr_u16Data, uint8_t Copy_u8Length);


/**
 * @brief This Function is used to Write data on specific address.
 *
 * @param Copy_u32Address address of location to be written.
 * @param Copy_u16Data data to be written
 */
void FPEC_voidFlashWriteHalfWord(uint32_t Copy_u32Address, uint16_t Copy_u16Data);

#endif /* FPEC_INTERFACE_H_ */
