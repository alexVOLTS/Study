################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../state_machine/state_machine.c 

OBJS += \
./state_machine/state_machine.o 

C_DEPS += \
./state_machine/state_machine.d 


# Each subdirectory must supply rules for building sources it contributes
state_machine/%.o state_machine/%.su: ../state_machine/%.c state_machine/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F407xx -DHSE_VALUE=8000000 -DUSE_FULL_LL_DRIVER -c -I../Inc -I../state_machine -I../st/STM32F4xx_HAL_Driver/Inc -I../ -I../st/CMSIS/Include -I../st/CMSIS/Device/ST/STM32F4xx/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-state_machine

clean-state_machine:
	-$(RM) ./state_machine/state_machine.d ./state_machine/state_machine.o ./state_machine/state_machine.su

.PHONY: clean-state_machine

