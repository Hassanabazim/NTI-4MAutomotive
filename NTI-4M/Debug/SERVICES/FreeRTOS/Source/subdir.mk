################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICES/FreeRTOS/Source/list.c \
../SERVICES/FreeRTOS/Source/queue.c \
../SERVICES/FreeRTOS/Source/tasks.c \
../SERVICES/FreeRTOS/Source/timers.c 

OBJS += \
./SERVICES/FreeRTOS/Source/list.o \
./SERVICES/FreeRTOS/Source/queue.o \
./SERVICES/FreeRTOS/Source/tasks.o \
./SERVICES/FreeRTOS/Source/timers.o 

C_DEPS += \
./SERVICES/FreeRTOS/Source/list.d \
./SERVICES/FreeRTOS/Source/queue.d \
./SERVICES/FreeRTOS/Source/tasks.d \
./SERVICES/FreeRTOS/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICES/FreeRTOS/Source/%.o: ../SERVICES/FreeRTOS/Source/%.c SERVICES/FreeRTOS/Source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\HAL\eep24C08" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\MCAL\I2C" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source\include" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source\portable" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source\portable\GCC" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\SERVICES\FreeRTOS\Source\portable\MemMang" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\HAL\keypad" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\MCAL\spi" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\LIB" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\MCAL\Dio" -I"D:\NTI-Embedded System\Automotive 4M\Projects\NTI-4M\MCAL\uart" -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


