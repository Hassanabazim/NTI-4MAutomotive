################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Button/button.c 

OBJS += \
./HAL/Button/button.o 

C_DEPS += \
./HAL/Button/button.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Button/%.o: ../HAL/Button/%.c HAL/Button/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\Projects\User-Password\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\Projects\User-Password\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\Projects\User-Password\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\Projects\User-Password\LIB" -I"D:\NTI-Embedded System\Automotive 4M\Projects\User-Password\MCAL\Dio" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


