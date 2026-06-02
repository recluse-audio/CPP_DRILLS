##
# 04_POINTERS_REFS_ARRAYS
#
# @file
# @version 0.1
GXX := g++
GXXFLAGS := -std=c++17 -Wall -Wextra

build:
	mkdir -p BUILD
	mkdir -p TESTS
	$(CXX) $(CXXFLAGS) -o BUILD/build SOURCE/main.cpp

test:
	mkdir -p BUILD
	mkdir -p TESTS
	$(CXX) $(CXXFLAGS) -o BUILD/test_build TESTS/test_main.cpp SOURCE/BufferProcessor.cpp
	./BUILD/test_build
clean:
	rm -rf BUILD/build BUILD/test_build
# end
