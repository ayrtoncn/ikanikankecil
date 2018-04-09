# Masukkan semua file cpp Anda
OBJS = objects/main.cpp objects/oop.cpp objects/Aquarium/Aquarium.cpp objects/Piranha/Piranha.cpp objects/Guppy/Guppy.cpp data_structures/LinkedList/LinkedList.hpp data_structures/Point/Point.cpp objects/Coin/Coin.cpp objects/Pet/Pet.cpp objects/Fish/Fish.cpp objects/Food/Food.cpp

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = oopquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME) -lm -lpthread -ggdb
