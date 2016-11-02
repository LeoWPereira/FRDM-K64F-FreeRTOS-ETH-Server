################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/devices/MK64F12/startup/system_MK64F12.c 

OBJS += \
./SDK/platform/devices/MK64F12/startup/system_MK64F12.o 

C_DEPS += \
./SDK/platform/devices/MK64F12/startup/system_MK64F12.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/devices/MK64F12/startup/%.o: ../SDK/platform/devices/MK64F12/startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DFSL_RTOS_FREE_RTOS -DCD_USING_GPIO -DSD_DISK_ENABLE=1 -D"CPU_MK64FN1M0VLL12" -D"FSL_OSA_BM_TIMER_CONFIG=0" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/inc" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\Middleware" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\Middleware\fsl_sd_disk" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\Middleware\fsl_sd_disk\src" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\main" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\Extras" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\lwip" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\ipv4" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\port" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/src/sim/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/src/clock/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/osa/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/CMSIS/Include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/src" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Sources" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/drivers/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/composite/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Static_Code/IO_Map" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Static_Code/Peripherals" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


