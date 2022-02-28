################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/HAL/SSD/SSD_program.c 

OBJS += \
./Src/HAL/SSD/SSD_program.o 

C_DEPS += \
./Src/HAL/SSD/SSD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Src/HAL/SSD/%.o: ../Src/HAL/SSD/%.c Src/HAL/SSD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DSTM32F401CCUx -DSTM32 -DSTM32F4 -c -I../Inc -I"E:/BlackPill/Labs/Base/Src/APP" -I"E:/BlackPill/Labs/Base/Src/MCAL" -I"E:/BlackPill/Labs/Base/Inc/MCAL" -I"E:/BlackPill/Labs/Base/Inc/HAL" -I"E:/BlackPill/Labs/Base/Inc/APP" -I"E:/BlackPill/Labs/Base/Inc/APP/LIB" -I"E:/BlackPill/Labs/Base/Inc/MCAL/GPIO" -I"E:/BlackPill/Labs/Base/Inc/MCAL/RCC" -I"E:/BlackPill/Labs/Base/Src/MCAL/RCC" -I"E:/BlackPill/Labs/Base/Inc/MCAL/ADC" -I"E:/BlackPill/Labs/Base/Src/MCAL/ADC" -I"E:/BlackPill/Labs/Base/Inc/HAL/SSD" -I"E:/BlackPill/Labs/Base/Src/HAL/SSD" -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-HAL-2f-SSD

clean-Src-2f-HAL-2f-SSD:
	-$(RM) ./Src/HAL/SSD/SSD_program.d ./Src/HAL/SSD/SSD_program.o

.PHONY: clean-Src-2f-HAL-2f-SSD

