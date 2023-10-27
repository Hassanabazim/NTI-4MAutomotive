################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/Spi.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/button.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/dio.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/eep_24c08.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/i2c.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/led.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/main.c \
../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/uart.c 

OBJS += \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/Spi.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/button.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/dio.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/eep_24c08.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/i2c.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/led.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/main.o \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/uart.o 

C_DEPS += \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/Spi.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/button.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/dio.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/eep_24c08.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/i2c.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/led.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/main.d \
./HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/uart.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/%.o: ../HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/%.c HAL/lcd/NTI_AVR_C4/NTI_AVR_C4/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\I2C" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\eep24C08" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\eeprom" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\keypad" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\spi" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\LIB" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\Dio" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\uart" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


