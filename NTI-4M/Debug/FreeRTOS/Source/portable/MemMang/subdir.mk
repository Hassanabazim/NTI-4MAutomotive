################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/MemMang/%.o: ../FreeRTOS/Source/portable/MemMang/%.c FreeRTOS/Source/portable/MemMang/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source\include" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source\portable" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source\portable\GCC" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\FreeRTOS\Source\portable\MemMang" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\HAL\keypad" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\MCAL\spi" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\LIB" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\MCAL\Dio" -I"D:\NTI-Embedded System\Automotive 4M\NTI-4M_Projects\NTI-4M\MCAL\uart" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


