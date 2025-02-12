################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/AFIO_program.c \
../Src/CAN.c \
../Src/CortexM3_Core_NVIC.c \
../Src/CortexM3_Core_SysTick.c \
../Src/DMA.c \
../Src/FPEC.c \
../Src/GPIO.c \
../Src/LED_program.c \
../Src/RCC.c \
../Src/SCB.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/AFIO_program.o \
./Src/CAN.o \
./Src/CortexM3_Core_NVIC.o \
./Src/CortexM3_Core_SysTick.o \
./Src/DMA.o \
./Src/FPEC.o \
./Src/GPIO.o \
./Src/LED_program.o \
./Src/RCC.o \
./Src/SCB.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/AFIO_program.d \
./Src/CAN.d \
./Src/CortexM3_Core_NVIC.d \
./Src/CortexM3_Core_SysTick.d \
./Src/DMA.d \
./Src/FPEC.d \
./Src/GPIO.d \
./Src/LED_program.d \
./Src/RCC.d \
./Src/SCB.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/AFIO_program.cyclo ./Src/AFIO_program.d ./Src/AFIO_program.o ./Src/AFIO_program.su ./Src/CAN.cyclo ./Src/CAN.d ./Src/CAN.o ./Src/CAN.su ./Src/CortexM3_Core_NVIC.cyclo ./Src/CortexM3_Core_NVIC.d ./Src/CortexM3_Core_NVIC.o ./Src/CortexM3_Core_NVIC.su ./Src/CortexM3_Core_SysTick.cyclo ./Src/CortexM3_Core_SysTick.d ./Src/CortexM3_Core_SysTick.o ./Src/CortexM3_Core_SysTick.su ./Src/DMA.cyclo ./Src/DMA.d ./Src/DMA.o ./Src/DMA.su ./Src/FPEC.cyclo ./Src/FPEC.d ./Src/FPEC.o ./Src/FPEC.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/LED_program.cyclo ./Src/LED_program.d ./Src/LED_program.o ./Src/LED_program.su ./Src/RCC.cyclo ./Src/RCC.d ./Src/RCC.o ./Src/RCC.su ./Src/SCB.cyclo ./Src/SCB.d ./Src/SCB.o ./Src/SCB.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

