L = program2
S = Scanner
PL = Planet
PA = Parser
H = Heap
FLAGS = -g -Wall -Werror -std=c++14

all: $(L)

$(L): $(PL).o $(L).o $(PA).o $(S).o 
	g++ $(FLAGS) $(PL).o $(PA).o $(L).o $(S).o -o $(L)

$(L).o: $(L).cpp $(H).h
	g++ $(FLAGS) -c $(L).cpp -o $(L).o

$(S).o: $(S).cpp $(S).h
	g++ $(FLAGS) -c $(S).cpp -o $(S).o

$(PL).o: $(PL).cpp $(PL).h
	g++ $(FLAGS) -c $(PL).cpp -o $(PL).o

$(PA).o: $(PA).cpp $(PA).h
	g++ $(FLAGS) -c $(PA).cpp -o $(PA).o

.PHONY: clean all run memcheck submit

clean:
	rm -rf $(L) *.o

run: all
	./$(L)

memcheck: all
	valgrind ./$(L)

