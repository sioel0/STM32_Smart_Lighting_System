################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Lights/Src/light.c \
../Drivers/Custom/Lights/Src/light_i2c.c 

OBJS += \
./Drivers/Custom/Lights/Src/light.o \
./Drivers/Custom/Lights/Src/light_i2c.o 

C_DEPS += \
./Drivers/Custom/Lights/Src/light.d \
./Drivers/Custom/Lights/Src/light_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Lights/Src/%.o Drivers/Custom/Lights/Src/%.su Drivers/Custom/Lights/Src/%.cyclo: ../Drivers/Custom/Lights/Src/%.c Drivers/Custom/Lights/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/Custom/Comm/Include -I../Drivers/Custom/Lights/Include -I../Drivers/Custom/Panic/Include -I../Drivers/Custom/Error/Include -I../Drivers/Custom/Sensors/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Lights-2f-Src

clean-Drivers-2f-Custom-2f-Lights-2f-Src:
	-$(RM) ./Drivers/Custom/Lights/Src/light.cyclo ./Drivers/Custom/Lights/Src/light.d ./Drivers/Custom/Lights/Src/light.o ./Drivers/Custom/Lights/Src/light.su ./Drivers/Custom/Lights/Src/light_i2c.cyclo ./Drivers/Custom/Lights/Src/light_i2c.d ./Drivers/Custom/Lights/Src/light_i2c.o ./Drivers/Custom/Lights/Src/light_i2c.su

.PHONY: clean-Drivers-2f-Custom-2f-Lights-2f-Src

