################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Error/Src/error.c 

OBJS += \
./Drivers/Custom/Error/Src/error.o 

C_DEPS += \
./Drivers/Custom/Error/Src/error.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Error/Src/%.o Drivers/Custom/Error/Src/%.su Drivers/Custom/Error/Src/%.cyclo: ../Drivers/Custom/Error/Src/%.c Drivers/Custom/Error/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/Custom/Comm/Include -I../Drivers/Custom/Lights/Include -I../Drivers/Custom/Panic/Include -I../Drivers/Custom/Error/Include -I../Drivers/Custom/Sensors/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Error-2f-Src

clean-Drivers-2f-Custom-2f-Error-2f-Src:
	-$(RM) ./Drivers/Custom/Error/Src/error.cyclo ./Drivers/Custom/Error/Src/error.d ./Drivers/Custom/Error/Src/error.o ./Drivers/Custom/Error/Src/error.su

.PHONY: clean-Drivers-2f-Custom-2f-Error-2f-Src

