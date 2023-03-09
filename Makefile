OBJ=obj/Plateau.o
CC=g++
CFLAGS=-g -Wall
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lGL

all: folders bin/monopoly 

folders:
	mkdir -p obj bin data

bin/monopoly: $(OBJ) obj/main.o
	$(CC) $(OBJ) obj/main.o -o bin/monopoly $(LIBS_SDL)

$(OBJ): src/Plateau.cpp src/Plateau.h 
	$(CC) $(CFLAGS) -c src/Plateau.cpp -o $(OBJ)

obj/main.o: src/main.cpp src/Plateau.h 
	$(CC) $(CFLAGS) -c src/main.cpp  -o obj/main.o

docs: doc/image.doxy
	doxygen doc/image.doxy

clean:
	rm -rf obj/* bin/* doc/html callgrind.out.*