################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Custom/Panic/Src/panic.c \
../Drivers/Custom/Panic/Src/panic_button.c \
../Drivers/Custom/Panic/Src/panic_buzzer.c \
../Drivers/Custom/Panic/Src/panic_timer.c 

OBJS += \
./Drivers/Custom/Panic/Src/panic.o \
./Drivers/Custom/Panic/Src/panic_button.o \
./Drivers/Custom/Panic/Src/panic_buzzer.o \
./Drivers/Custom/Panic/Src/panic_timer.o 

C_DEPS += \
./Drivers/Custom/Panic/Src/panic.d \
./Drivers/Custom/Panic/Src/panic_button.d \
./Drivers/Custom/Panic/Src/panic_buzzer.d \
./Drivers/Custom/Panic/Src/panic_timer.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Custom/Panic/Src/%.o Drivers/Custom/Panic/Src/%.su Drivers/Custom/Panic/Src/%.cyclo: ../Drivers/Custom/Panic/Src/%.c Drivers/Custom/Panic/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Custom-2f-Panic-2f-Src

clean-Drivers-2f-Custom-2f-Panic-2f-Src:
	-$(RM) ./Drivers/Custom/Panic/Src/panic.cyclo ./Drivers/Custom/Panic/Src/panic.d ./Drivers/Custom/Panic/Src/panic.o ./Drivers/Custom/Panic/Src/panic.su ./Drivers/Custom/Panic/Src/panic_button.cyclo ./Drivers/Custom/Panic/Src/panic_button.d ./Drivers/Custom/Panic/Src/panic_button.o ./Drivers/Custom/Panic/Src/panic_button.su ./Drivers/Custom/Panic/Src/panic_buzzer.cyclo ./Drivers/Custom/Panic/Src/panic_buzzer.d ./Drivers/Custom/Panic/Src/panic_buzzer.o ./Drivers/Custom/Panic/Src/panic_buzzer.su ./Drivers/Custom/Panic/Src/panic_timer.cyclo ./Drivers/Custom/Panic/Src/panic_timer.d ./Drivers/Custom/Panic/Src/panic_timer.o ./Drivers/Custom/Panic/Src/panic_timer.su

.PHONY: clean-Drivers-2f-Custom-2f-Panic-2f-Src

