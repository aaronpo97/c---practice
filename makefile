CXX := clang++
CXXFLAGS := -Wall -Wextra -O2 -std=c++20
SRC := $(shell find . -name '*.cpp')
BIN := $(patsubst ./%.cpp,build/%.out,$(SRC))

.PHONY: all clean

all: $(BIN)

build/%.out: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf build
