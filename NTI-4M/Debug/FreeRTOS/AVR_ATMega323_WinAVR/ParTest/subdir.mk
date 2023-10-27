################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/AVR_ATMega323_WinAVR/ParTest/ParTest.c 

OBJS += \
./FreeRTOS/AVR_ATMega323_WinAVR/ParTest/ParTest.o 

C_DEPS += \
./FreeRTOS/AVR_ATMega323_WinAVR/ParTest/ParTest.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/AVR_ATMega323_WinAVR/ParTest/%.o: ../FreeRTOS/AVR_ATMega323_WinAVR/ParTest/%.c FreeRTOS/AVR_ATMega323_WinAVR/ParTest/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\AVR_ATMega323_WinAVR" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\AVR_ATMega323_WinAVR\ParTest" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\AVR_ATMega323_WinAVR\serial" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source\include" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source\portable" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source\portable\GCC" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source\portable\GCC\ATMega323" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\FreeRTOS\Source\portable\MemMang" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\Button" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\keypad" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\spi" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\lcd" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\HAL\Led" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\LIB" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\Dio" -I"D:\NTI-Embedded System\Automotive 4M\AVR\Drives\NTI-4M\MCAL\uart" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


