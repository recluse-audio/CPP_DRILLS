CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
CATCH_DIR := ../../../SUBMODULES/Catch2/extras

build:
	mkdir -p BUILD
	$(CXX) $(CXXFLAGS) -o BUILD/templates_build SOURCE/main.cpp

test: build BUILD/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -I$(CATCH_DIR) -ISOURCE -o BUILD/templates_tests_build \
		TESTS/test_main.cpp BUILD/catch_amalgamated.o
	./BUILD/templates_tests_build

BUILD/catch_amalgamated.o: $(CATCH_DIR)/catch_amalgamated.cpp
	mkdir -p BUILD
	$(CXX) -std=c++17 -I$(CATCH_DIR) -c -o BUILD/catch_amalgamated.o $(CATCH_DIR)/catch_amalgamated.cpp

clean:
	rm -rf BUILD
