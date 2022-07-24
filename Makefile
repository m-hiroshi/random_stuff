OBJ = atoi kmp lcsi Rabin-Karp

all: $(OBJ)

%: %.cpp
	g++ --std=c++17 -o $@ $<

clean:
	rm -f $(OBJ)
