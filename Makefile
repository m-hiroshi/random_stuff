OBJ = atoi kmp lcsi Rabin-Karp

all: $(OBJ)

%: %.cpp
	mkdir -p bin
	g++ --std=c++17 -o bin/$@ $<

clean:
	rm -f $(OBJ)
