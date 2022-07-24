OBJ = prim 
FLAGS = -std=c++17

all: $(OBJ)

util.o: util.cpp util.h
	g++ $(FLAGS) -c -o $@ util.cpp

%: %.cpp util.o
	g++ $(FLAGS) -o $@ $< util.o

clean:
	rm -f $(OBJ)
