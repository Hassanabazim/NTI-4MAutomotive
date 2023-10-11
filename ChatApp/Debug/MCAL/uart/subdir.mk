################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/uart/uart.c 

OBJS += \
./MCAL/uart/uart.o 

C_DEPS += \
./MCAL/uart/uart.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/uart/%.o: ../MCAL/uart/%.c MCAL/uart/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\LIB" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\MCAL\Dio" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\MCAL\Exti" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\MCAL\spi" -I"D:\NTI-Embedded System\Automotive 4M\Projects\ChatApp\MCAL\uart" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


