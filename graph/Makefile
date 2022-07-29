OBJ = dijkstra floyd_warshall ford_fulkerson kruskal prim
FLAGS = -std=c++17

.PHONY: all mkdir clean

all: $(OBJ)

util.o: util.cpp util.h
	g++ $(FLAGS) -c -o $@ util.cpp

%: %.cpp util.o mkdir
	g++ $(FLAGS) -o bin/$@ $< util.o

mkdir:
	mkdir -p bin

clean:
	rm -rf bin util.o
