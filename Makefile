CC := gcc
ASM := nasm

C_STD = 99

CFLAGS := -O2 -Wall -Wextra -Wpedantic -std=gnu$(C_STD)
C_EXT_FLAGS := -c -MMD -shared 

LDFLAG =
ARGS :=

TARGET := hawk

SRC_DIR = src
OBJ_DIR = obj
REL_DIR = bin
INC_DIR = inc

LD_PATH := $(OBJ_DIR)

C_SRCS = $(wildcard $(SRC_DIR)/*.c)
ASM_SRCS = $(wildcard $(SRC_DIR)/*.asm)
C_DEPS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.d,$(C_SRCS))
C_OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/lib%.so,$(C_SRCS))

RELEASE_FILE := hawk
.PHONY: all debug run clean

all : $(REL_DIR)/$(RELEASE_FILE)
debug: all
debug:
    gdb -q -x .gdbinit --args $(REL_DIR)/$(RELEASE_FILE) $(ARGS)
run: all
    ./$(REL_DIR)/$(RELEASE_FILE) $(ARGS)
clean:
    rm -rf $(OBJ_DIR)/*
    rm -rf $(REL_DIR)/out

$(REL_DIR)/$(RELEASE_FILE): $(C_OBJS) $(CXX_OBJS) $(TARGET)
    $(CC) $(C_FLAGS) $(TARGET) -o $@ -L$(LD_PATH) $(patsubst obj/lib%.so,-l%,$(C_OBJS)) $(patsubst obj/lib%.so,-l%,$(CXX_OBJS)) $(patsubst %,-I%,$(INC_DIR)) $(LDFLAG)

$(C_OBJS) : $(OBJ_DIR)/lib%.so : $(SRC_DIR)/%.c 
    $(CC) $(C_FLAGS) $(C_EXT_FLAGS) $< -o $@ $(LDFLAG)

-include $(C_DEPS)
