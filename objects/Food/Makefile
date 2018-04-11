# Masukkan semua file cpp Anda
OBJS = ../../data_structures/Point/Point.cpp Food.cpp driver_food.cpp ../oop.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = driver_food
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) -lm -pthread -lpthread -ggdb
