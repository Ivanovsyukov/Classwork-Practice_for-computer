CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=create_new_bmp.cpp bmp_function.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bmp_creator.exe

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	del *.o