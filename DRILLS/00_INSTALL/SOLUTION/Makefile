CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
CATCH_DIR := ../../../SUBMODULES/Catch2/extras

test: BUILD/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -I$(CATCH_DIR) -o BUILD/install_tests_build TESTS/test_main.cpp BUILD/catch_amalgamated.o
	./BUILD/install_tests_build

BUILD/catch_amalgamated.o: $(CATCH_DIR)/catch_amalgamated.cpp
	mkdir -p BUILD
	$(CXX) -std=c++17 -I$(CATCH_DIR) -c -o BUILD/catch_amalgamated.o $(CATCH_DIR)/catch_amalgamated.cpp

clean:
	rm -rf BUILD
