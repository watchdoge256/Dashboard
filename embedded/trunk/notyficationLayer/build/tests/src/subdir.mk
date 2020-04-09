# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/src/notification_com.cpp \
../tests/src/notification_init.cpp \
../tests/src/notification_reg.cpp


OBJS += \
./tests/src/notification_com.o \
./tests/src/notification_init.o \
./tests/src/notification_reg.o

CPP_DEPS += \
./tests/src/notification_com.d \
./tests/src/notification_init.d \
./tests/src/notification_reg.d

CPP_INC += \
-I"../inc" \


# Each subdirectory must supply rules for building sources it contributes
tests/src/%.o: ../tests/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ $(CPP_INC) -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


