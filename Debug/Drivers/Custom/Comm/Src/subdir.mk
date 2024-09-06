################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Comm/Src/comm.c \
../Drivers/Custom/Comm/Src/protocol.c 

OBJS += \
./Drivers/Custom/Comm/Src/comm.o \
./Drivers/Custom/Comm/Src/protocol.o 

C_DEPS += \
./Drivers/Custom/Comm/Src/comm.d \
./Drivers/Custom/Comm/Src/protocol.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Comm/Src/%.o Drivers/Custom/Comm/Src/%.su Drivers/Custom/Comm/Src/%.cyclo: ../Drivers/Custom/Comm/Src/%.c Drivers/Custom/Comm/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Drivers/Custom/Comm/Include -I../Drivers/Custom/Lights/Include -I../Drivers/Custom/Panic/Include -I../Drivers/Custom/Error/Include -I../Drivers/Custom/Sensors/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Comm-2f-Src

clean-Drivers-2f-Custom-2f-Comm-2f-Src:
	-$(RM) ./Drivers/Custom/Comm/Src/comm.cyclo ./Drivers/Custom/Comm/Src/comm.d ./Drivers/Custom/Comm/Src/comm.o ./Drivers/Custom/Comm/Src/comm.su ./Drivers/Custom/Comm/Src/protocol.cyclo ./Drivers/Custom/Comm/Src/protocol.d ./Drivers/Custom/Comm/Src/protocol.o ./Drivers/Custom/Comm/Src/protocol.su

.PHONY: clean-Drivers-2f-Custom-2f-Comm-2f-Src

