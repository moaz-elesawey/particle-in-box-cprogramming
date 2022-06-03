CC = gcc

NAME = PIB.exe

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

CC_FLAGS = -g -Wall -mcmodel=medium
CC_LINKS = -lm $(CC_IN) -I $(INC_DIR)
NC_LINKS = -lnetcdf -lcurl
NC_LIB = -L/usr/local/lib
NC_INC = -I/usr/local/include

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/$(NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ $(CC_LINKS) $(NC_LINKS) $(NC_LIB) $(NC_INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ -I $(CC_LINKS)

clean:
	rm -r $(BIN_DIR)/*
	rm -r $(OBJ_DIR)/*

