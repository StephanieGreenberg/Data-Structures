L = program3
G = Galaxy
P = Planet
FLAGS = -g -Wall -Werror -std=c++14

all: $(L)

$(L): $(L).o $(G).o $(P).o
	g++ $(FLAGS) $(L).o $(G).o $(P).o -o $(L)

$(L).o: $(L).cpp
	g++ $(FLAGS) -c $(L).cpp -o $(L).o 

$(G).o: $(G).cpp $(G).h
	g++ $(FLAGS) -c $(G).cpp -o $(G).o 

$(P).o: $(P).cpp $(P).h
	g++ $(FLAGS) -c $(P).cpp -o $(P).o 

.PHONY: clean all run memcheck

clean:
	rm -rf $(L) *.o
debug: all
	gdb ./$(L)

run: all
	./$(L)

memcheck: all
	valgrind ./$(L)
