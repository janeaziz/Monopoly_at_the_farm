CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lSDL2 -lSDL2_image
SOURCES=Plateau.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=jeu

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
