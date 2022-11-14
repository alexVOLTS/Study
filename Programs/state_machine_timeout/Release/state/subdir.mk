################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../state/state.c 

OBJS += \
./state/state.o 

C_DEPS += \
./state/state.d 


# Each subdirectory must supply rules for building sources it contributes
state/%.o state/%.su: ../state/%.c state/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F407xx -DHSE_VALUE=8000000 -DUSE_FULL_LL_DRIVER -c -I../Inc -I../state -I../st/STM32F4xx_HAL_Driver/Inc -I../ -I../st/CMSIS/Include -I../st/CMSIS/Device/ST/STM32F4xx/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-state

clean-state:
	-$(RM) ./state/state.d ./state/state.o ./state/state.su

.PHONY: clean-state

