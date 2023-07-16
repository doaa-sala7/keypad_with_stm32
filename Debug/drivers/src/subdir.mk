################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/gpio.c \
../drivers/src/keypad.c 

OBJS += \
./drivers/src/gpio.o \
./drivers/src/keypad.o 

C_DEPS += \
./drivers/src/gpio.d \
./drivers/src/keypad.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"C:/Users/Doaa/workspace/lab5keypad/drivers/include" -I"C:/Users/Doaa/workspace/lab5keypad/inc" -I"C:/Users/Doaa/workspace/lab5keypad/CMSIS/device" -I"C:/Users/Doaa/workspace/lab5keypad/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


