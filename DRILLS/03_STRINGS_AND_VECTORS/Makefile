CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

build:
	mkdir -p BUILD
	$(CXX) $(CXXFLAGS) -o BUILD/build SOURCE/main.cpp SOURCE/StringReverse.cpp

test:
	mkdir -P TESTS
	$(CXX) $(CXXFLAGS) -o TESTS/test_build TESTS/test_main.cpp SOURCE/StringReverse.h
	./TESTS/test_build

clean:
	rm -f BUILD/build TESTS/test_build
