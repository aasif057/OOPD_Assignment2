# Compiler
CXX = g++

# Source files
SRC = q1.cpp   # Add other source files as needed
OBJ = $(SRC:.cpp=.o)

# Binary names
DEBUG_BIN = q1_debug
OPT_BIN = q1_opt

# Compiler flags
CXXFLAGS_DEBUG = -g -Wall
CXXFLAGS_OPT = -O2 -Wall

# Default target
all: $(DEBUG_BIN) $(OPT_BIN)

# Rule to build the debug version
$(DEBUG_BIN): $(OBJ)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^

# Rule to build the optimized version
$(OPT_BIN): $(OBJ)
	$(CXX) $(CXXFLAGS_OPT) -o $@ $^

# Rule to compile the source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJ) $(DEBUG_BIN) $(OPT_BIN)

# Phony targets
.PHONY: all clean
