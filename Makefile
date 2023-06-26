CC = gcc

NAME = PIB.exe

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# CC_FLAGS = -g -Wall -mcmodel=medium
CC_FLAGS = -O3 -mcmodel=medium
CC_LINKS = -lm $(CC_IN) -I $(INC_DIR)
NC_LINKS = -lnetcdf -lcurl
NC_LIB = 
NC_INC = 

H5_LIB = -L/usr/lib/x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu/hdf5/serial
H5_INC = 
H5_LINKS = -lhdf5


SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/$(NAME)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) -o $@ $(H5_LIB) $(H5_INC) $(CC_LINKS) $(H5_LINKS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CC_FLAGS) -c $< -o $@ $(H5_INC) $(H5_LIB) $(CC_LINKS)

clean:
	rm -r $(BIN_DIR)/*
	rm -r $(OBJ_DIR)/*

