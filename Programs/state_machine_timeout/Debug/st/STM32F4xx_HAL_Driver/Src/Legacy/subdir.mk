################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.c \
../st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.c 

OBJS += \
./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o \
./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.o 

C_DEPS += \
./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d \
./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.d 


# Each subdirectory must supply rules for building sources it contributes
st/STM32F4xx_HAL_Driver/Src/Legacy/%.o st/STM32F4xx_HAL_Driver/Src/Legacy/%.su: ../st/STM32F4xx_HAL_Driver/Src/Legacy/%.c st/STM32F4xx_HAL_Driver/Src/Legacy/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -DUSE_FULL_LL_DRIVER -c -I../Inc -I../st/STM32F4xx_HAL_Driver/Inc -I../ -I../st/CMSIS/Include -I../st/CMSIS/Device/ST/STM32F4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-st-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

clean-st-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy:
	-$(RM) ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.d ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.o ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_can.su ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.d ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.o ./st/STM32F4xx_HAL_Driver/Src/Legacy/stm32f4xx_hal_eth.su

.PHONY: clean-st-2f-STM32F4xx_HAL_Driver-2f-Src-2f-Legacy

