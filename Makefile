OBJ = atoi kmp lcs rabin_karp

.PHONY = all clean mkdir

all: $(OBJ)

%: %.cpp mkdir
	g++ --std=c++17 -o bin/$@ $<

mkdir:
	mkdir -p bin

clean:
	rm -rf bin
