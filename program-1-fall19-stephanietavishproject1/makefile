cFlags = -Wall -Werror -g -std=c++14 


all: Planet.o List.o Vector.o Star.o program1.o
	g++ $(cFlags) List.o Planet.o Vector.o Star.o program1.o -o program1  

program1.o: program1.cpp Star.h Planet.h List.h Vector.h
	g++ $(cFlags) -c program1.cpp -o program1.o 

Planet.o: Planet.cpp Planet.h
	g++ $(cFlags) -c Planet.cpp -o Planet.o

List.o: List.cpp List.h
	g++ $(cFlags) -c List.cpp -o List.o

Vector.o: Vector.cpp Vector.h
	g++ $(cFlags) -c Vector.cpp -o Vector.o

Star.o: Star.cpp Star.h
	g++ $(cFlags) -c Star.cpp -o Star.o

.PHONY: clean all run memcheck

run:	all
	./program1 

clean:
	rm -rf program1 *.o 

memcheck: all
	valgrind ./program1
