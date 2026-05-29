CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra

build:
	$(CXX) $(CXXFLAGS) -o BUILD/hello_world_build SOURCE/main.cpp

test:
	$(CXX) $(CXXFLAGS) -o TESTS/hello_world_tests_build TESTS/test_main.cpp
	./TESTS/hello_world_tests_build

clean:
	rm -f BUILD/hello_world_buld TESTS/hello_world_tests_build
