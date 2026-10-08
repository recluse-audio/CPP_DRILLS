CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra
SANITIZE_FLAGS := -fsanitize=address -g
CATCH_DIR := ../../../SUBMODULES/Catch2/extras
UNIT_SOURCES := SOURCE/BufferProcessor.cpp

build:
	mkdir -p BUILD
	$(CXX) $(CXXFLAGS) -o BUILD/buffer_processor_build SOURCE/main.cpp $(UNIT_SOURCES)

test: build BUILD/catch_amalgamated.o
	$(CXX) $(CXXFLAGS) $(SANITIZE_FLAGS) -I$(CATCH_DIR) -ISOURCE -o BUILD/buffer_processor_tests_build \
		TESTS/test_main.cpp $(UNIT_SOURCES) BUILD/catch_amalgamated.o
	./BUILD/buffer_processor_tests_build

BUILD/catch_amalgamated.o: $(CATCH_DIR)/catch_amalgamated.cpp
	mkdir -p BUILD
	$(CXX) -std=c++17 -I$(CATCH_DIR) -c -o BUILD/catch_amalgamated.o $(CATCH_DIR)/catch_amalgamated.cpp

clean:
	rm -rf BUILD
