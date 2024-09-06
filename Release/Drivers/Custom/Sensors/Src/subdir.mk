################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Sensors/Src/sensors_light_sensor.c \
../Drivers/Custom/Sensors/Src/sensors_movement_sensor.c 

OBJS += \
./Drivers/Custom/Sensors/Src/sensors_light_sensor.o \
./Drivers/Custom/Sensors/Src/sensors_movement_sensor.o 

C_DEPS += \
./Drivers/Custom/Sensors/Src/sensors_light_sensor.d \
./Drivers/Custom/Sensors/Src/sensors_movement_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Sensors/Src/%.o Drivers/Custom/Sensors/Src/%.su Drivers/Custom/Sensors/Src/%.cyclo: ../Drivers/Custom/Sensors/Src/%.c Drivers/Custom/Sensors/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Sensors-2f-Src

clean-Drivers-2f-Custom-2f-Sensors-2f-Src:
	-$(RM) ./Drivers/Custom/Sensors/Src/sensors_light_sensor.cyclo ./Drivers/Custom/Sensors/Src/sensors_light_sensor.d ./Drivers/Custom/Sensors/Src/sensors_light_sensor.o ./Drivers/Custom/Sensors/Src/sensors_light_sensor.su ./Drivers/Custom/Sensors/Src/sensors_movement_sensor.cyclo ./Drivers/Custom/Sensors/Src/sensors_movement_sensor.d ./Drivers/Custom/Sensors/Src/sensors_movement_sensor.o ./Drivers/Custom/Sensors/Src/sensors_movement_sensor.su

.PHONY: clean-Drivers-2f-Custom-2f-Sensors-2f-Src

