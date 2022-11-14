################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.c \
../st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.c 

OBJS += \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.o \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.o 

C_DEPS += \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.d \
./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.d 


# Each subdirectory must supply rules for building sources it contributes
st/STM32F4xx_HAL_Driver/Src/%.o st/STM32F4xx_HAL_Driver/Src/%.su: ../st/STM32F4xx_HAL_Driver/Src/%.c st/STM32F4xx_HAL_Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F407xx -DHSE_VALUE=8000000 -DUSE_FULL_LL_DRIVER -c -I../Inc -I../state -I../st/STM32F4xx_HAL_Driver/Inc -I../ -I../st/CMSIS/Include -I../st/CMSIS/Device/ST/STM32F4xx/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-st-2f-STM32F4xx_HAL_Driver-2f-Src

clean-st-2f-STM32F4xx_HAL_Driver-2f-Src:
	-$(RM) ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_adc.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_crc.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dac.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_dma2d.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_exti.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmpi2c.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_gpio.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_i2c.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_lptim.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_pwr.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rcc.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rng.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_rtc.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_spi.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_tim.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usart.su ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.d ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.o ./st/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_utils.su

.PHONY: clean-st-2f-STM32F4xx_HAL_Driver-2f-Src

