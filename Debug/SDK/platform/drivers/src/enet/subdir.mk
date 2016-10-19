################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SDK/platform/drivers/src/enet/fsl_enet_common.c \
../SDK/platform/drivers/src/enet/fsl_enet_driver.c 

OBJS += \
./SDK/platform/drivers/src/enet/fsl_enet_common.o \
./SDK/platform/drivers/src/enet/fsl_enet_driver.o 

C_DEPS += \
./SDK/platform/drivers/src/enet/fsl_enet_common.d \
./SDK/platform/drivers/src/enet/fsl_enet_driver.d 


# Each subdirectory must supply rules for building sources it contributes
SDK/platform/drivers/src/enet/%.o: ../SDK/platform/drivers/src/enet/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g3 -DFSL_RTOS_FREE_RTOS -D"CPU_MK64FN1M0VLL12" -D"FSL_OSA_BM_TIMER_CONFIG=0" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/inc" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\lwip" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\src\include\ipv4" -I"C:\Users\leona\workspace.kds\FreeRTOS-lwIP-IoT\lwip\port" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/hal/src/sim/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/src/clock/MK64F12" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/system/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/osa/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/CMSIS/Include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/include" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/src" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/utilities/inc" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code/SDK/platform/devices/MK64F12/startup" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Sources" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/Generated_Code" -I"C:/Users/leona/workspace.kds/FreeRTOS-lwIP-IoT/SDK/platform/drivers/inc" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

