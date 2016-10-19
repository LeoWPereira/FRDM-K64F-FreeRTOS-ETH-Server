################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Cpu.c \
../Generated_Code/FRTOS1.c \
../Generated_Code/KSDK1.c \
../Generated_Code/UTIL1.c \
../Generated_Code/clockMan1.c \
../Generated_Code/croutine.c \
../Generated_Code/eNet1.c \
../Generated_Code/event_groups.c \
../Generated_Code/gpio1.c \
../Generated_Code/hardware_init.c \
../Generated_Code/heap_1.c \
../Generated_Code/heap_2.c \
../Generated_Code/heap_3.c \
../Generated_Code/heap_4.c \
../Generated_Code/heap_5.c \
../Generated_Code/list.c \
../Generated_Code/osa1.c \
../Generated_Code/pin_init.c \
../Generated_Code/port.c \
../Generated_Code/queue.c \
../Generated_Code/tasks.c \
../Generated_Code/timers.c 

OBJS += \
./Generated_Code/Cpu.o \
./Generated_Code/FRTOS1.o \
./Generated_Code/KSDK1.o \
./Generated_Code/UTIL1.o \
./Generated_Code/clockMan1.o \
./Generated_Code/croutine.o \
./Generated_Code/eNet1.o \
./Generated_Code/event_groups.o \
./Generated_Code/gpio1.o \
./Generated_Code/hardware_init.o \
./Generated_Code/heap_1.o \
./Generated_Code/heap_2.o \
./Generated_Code/heap_3.o \
./Generated_Code/heap_4.o \
./Generated_Code/heap_5.o \
./Generated_Code/list.o \
./Generated_Code/osa1.o \
./Generated_Code/pin_init.o \
./Generated_Code/port.o \
./Generated_Code/queue.o \
./Generated_Code/tasks.o \
./Generated_Code/timers.o 

C_DEPS += \
./Generated_Code/Cpu.d \
./Generated_Code/FRTOS1.d \
./Generated_Code/KSDK1.d \
./Generated_Code/UTIL1.d \
./Generated_Code/clockMan1.d \
./Generated_Code/croutine.d \
./Generated_Code/eNet1.d \
./Generated_Code/event_groups.d \
./Generated_Code/gpio1.d \
./Generated_Code/hardware_init.d \
./Generated_Code/heap_1.d \
./Generated_Code/heap_2.d \
./Generated_Code/heap_3.d \
./Generated_Code/heap_4.d \
./Generated_Code/heap_5.d \
./Generated_Code/list.d \
./Generated_Code/osa1.d \
./Generated_Code/pin_init.d \
./Generated_Code/port.d \
./Generated_Code/queue.d \
./Generated_Code/tasks.d \
./Generated_Code/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DFSL_RTOS_FREE_RTOS -D"CPU_MK64FN1M0VLL12" -D"FSL_OSA_BM_TIMER_CONFIG=0" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/inc" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\lwip" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\ipv4" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\port" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/src/sim/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/src/clock/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/osa/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/CMSIS/Include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/src" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Sources" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


