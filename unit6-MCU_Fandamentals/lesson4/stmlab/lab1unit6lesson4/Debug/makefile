################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
lab1unit6lesson4.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
lab1unit6lesson4.list \

OBJCOPY_BIN += \
lab1unit6lesson4.bin \


# All Target
all: lab1unit6lesson4.elf secondary-outputs

# Tool invocations
lab1unit6lesson4.elf: $(OBJS) $(USER_OBJS) D:\full_diploma\ES_Online_Diploma_KS\second-term\unit6\MCU_FUNDAMENTALS\lesson4\lab1\stmlab\lab1unit6lesson4\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "lab1unit6lesson4.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\full_diploma\ES_Online_Diploma_KS\second-term\unit6\MCU_FUNDAMENTALS\lesson4\lab1\stmlab\lab1unit6lesson4\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="lab1unit6lesson4.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

lab1unit6lesson4.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "lab1unit6lesson4.list"
	@echo 'Finished building: $@'
	@echo ' '

lab1unit6lesson4.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "lab1unit6lesson4.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
