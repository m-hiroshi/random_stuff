OBJS = merge_sort.o heap_sort.o quick_sort.o
CPPFLAGS = --std=c++17

.PHONY: clean

sort: $(OBJS) main.cpp
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/$@ $^

%.o: %.cpp %.hpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm -f $(OBJS)
	rm -rf bin
