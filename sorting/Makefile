CPPFLAGS = --std=c++17

sort: merge_sort.o main.cpp
	g++ $(CPPFLAGS) -o $@ $^

%.o: %.cpp %.hpp
	g++ $(CPPFLAGS) -c $<

clean:
	rm *.o sort