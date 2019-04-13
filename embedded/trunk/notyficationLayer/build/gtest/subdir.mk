################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../../../tests/gtest/gtest-all.cpp 

OBJS += \
./gtest/gtest-all.o 

CPP_DEPS += \
./gtest/gtest-all.d 


# Each subdirectory must supply rules for building sources it contributes
gtest/%.o: ../../../tests/gtest/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ $(CPP_INC) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


