OBJS = merge_sort.o heap_sort.o quick_sort.o
CPPFLAGS = --std=c++17

sort: $(OBJS) main.cpp
	g++ $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm -f $(OBJS) sort