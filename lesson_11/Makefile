CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=farm.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=farm.exe

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.o $(EXECUTABLE)