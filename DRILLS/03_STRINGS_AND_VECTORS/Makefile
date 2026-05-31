CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

build:
	mkdir -p BUILD
	$(CXX) $(CXXFLAGS) -o BUILD/build SOURCE/main.cpp SOURCE/StringModifier.cpp

test:
	mkdir -p TESTS
	$(CXX) $(CXXFLAGS) -o TESTS/test_build TESTS/test_main.cpp SOURCE/StringModifier.cpp
	./TESTS/test_build

clean:
	rm -f BUILD/build TESTS/test_build
