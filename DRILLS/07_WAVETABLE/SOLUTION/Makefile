CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
CATCH_DIR := ../../../SUBMODULES/Catch2/extras
UNIT_SOURCES := SOURCE/Wavetable.cpp

build:
	cmake -S . -B BUILD/cmake
	cmake --build BUILD/cmake

test: BUILD/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) -I$(CATCH_DIR) -ISOURCE -o BUILD/wavetable_tests_build \
		TESTS/test_main.cpp $(UNIT_SOURCES) BUILD/catch_amalgamated.o
	./BUILD/wavetable_tests_build

BUILD/catch_amalgamated.o: $(CATCH_DIR)/catch_amalgamated.cpp
	mkdir -p BUILD
	$(CXX) -std=c++17 -I$(CATCH_DIR) -c -o BUILD/catch_amalgamated.o $(CATCH_DIR)/catch_amalgamated.cpp

clean:
	rm -rf BUILD
