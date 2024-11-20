CXX = g++
CXXFLAGS = -Wall --std=c++17

comp_test_book: test_book.cpp book.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_book.cpp book.cpp catch_amalgamated.cpp -o test_book.o

comp_test_library: test_library.cpp book.cpp library.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_library.cpp book.cpp library.cpp catch_amalgamated.cpp -o test_library.o

comp_test_memory: test_memory.cpp book.cpp library.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_memory.cpp book.cpp library.cpp catch_amalgamated.cpp -o test_memory.o

test_book: comp_test_book
	./test_book.o

test_library: comp_test_library
	./test_library.o

test_memory: comp_test_memory
	./test_memory.o

clean:
	rm -f main test_book.o test_library.o test_memory.o