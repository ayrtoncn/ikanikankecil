# Masukkan semua file cpp Anda
OBJS = ../../data_structures/Point/Point.cpp Fish.cpp driver_fish.cpp ../oop.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = driver_fish
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) -lm -lpthread -ggdb
