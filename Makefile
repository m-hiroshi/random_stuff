OBJ = atoi kmp lcs

all: $(OBJ)

%: %.cpp
	g++ --std=c++17 -o $@ $<

clean:
	rm -f $(OBJ)
