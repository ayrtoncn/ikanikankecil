# Masukkan semua file cpp Anda
OBJS = ../main.cpp ../oop.cpp Guppy.cpp ../../data_structures/Point/Point.cpp ../Coin/Coin.cpp ../Fish/Fish.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) -lm -lpthread -ggdb
