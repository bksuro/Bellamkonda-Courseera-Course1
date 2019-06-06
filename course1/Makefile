#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the platforms MSP432 and HOSt.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      %.i         - generates the preprocessed output of all c-program 
#                      implementation files
#      %.asm       - generates assembly output of c-program implementation files 
#                      and the final output executable
#      %.o         - generates the object file for all c-source files, but doesn't 
#                      link, by specifiying the object file
#      compile-all - compiles all object files, but doesn't link
#      build       - compiles all object files and links into a final executable
#      clean       - will remove all compiled objects, preprocessed outputs, assembly 
#                      outputs, executable files, and build output files
#
# Platform Overrides:
#      PLATFORM=MSP432 - target embedded system arm cortex m4 architecture
#      PLATFORM=HOST   - host embedded system
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = 

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
  LINKER_FILE = ./msp432p401r.lds
  CPU = cortex-m4
  ARCH = armv7e-m
  SPECS = nosys.specs
endif 

# Compiler Flags and Defines
TARGET = c1m2
ifeq ($(PLATFORM), MSP432)
  CC = arm-none-eabi-gcc
  LD = arm-none-eabi-ld
  LDFLAGS = -Wl,-Map=$(TARGET).map $(INCLUDES) -T $(LINKER_FILE) 
  CFLAGS = -Wall -Werror -g -O0 -std=c99 -mcpu=$(CPU) -mthumb -march=$(ARCH) \
             -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS)
  CPPFLAGS = -D$(PLATFORM) -MD
endif 
ifeq ($(PLATFORM), HOST)
  CC = gcc
  LD = 
  LDFLAGS = -Wl,-Map=$(TARGET).map $(INCLUDES)
  CFLAGS = -Wall -Werror -g -O0 -std=c99
  CPPFLAGS = -D$(PLATFORM) -MD
endif 

#OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

%.i : %.c
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -E $< -o $@

%.asm : %.c
	$(CC) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	objdump -S $@    
    
.PHONY : build    
build : $(TARGET).out
$(TARGET).out : $(SRCS)    
	$(CC) $(SRCS) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -o $(TARGET).out
	size $(TARGET).out

.PHONY : compile-all
compile-all : $(SRCS)    
	$(CC) $(SRCS) $(LDFLAGS) $(CPPFLAGS) $(CFLAGS) -c

.PHONY : clean
clean :     
	rm -f *.o *.asm *.i *.d *.map *.out
