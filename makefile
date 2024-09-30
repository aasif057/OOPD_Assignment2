# Compiler
CXX = g++

# Source files for both programs
SRC_Q1 = q1.cpp
SRC_Q2 = q2.cpp

# Object files
OBJ_Q1 = $(SRC_Q1:.cpp=.o)
OBJ_Q2 = $(SRC_Q2:.cpp=.o)

# Binary names for q1 and q2
DEBUG_BIN_Q1 = q1_debug
OPT_BIN_Q1 = q1_opt

DEBUG_BIN_Q2 = q2_debug
OPT_BIN_Q2 = q2_opt

# Compiler flags
CXXFLAGS_DEBUG = -g -Wall
CXXFLAGS_OPT = -O2 -Wall

# Default target to build everything
all: $(DEBUG_BIN_Q1) $(OPT_BIN_Q1) $(DEBUG_BIN_Q2) $(OPT_BIN_Q2)

# Rule to build q1 debug version
$(DEBUG_BIN_Q1): $(OBJ_Q1)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^

# Rule to build q1 optimized version
$(OPT_BIN_Q1): $(OBJ_Q1)
	$(CXX) $(CXXFLAGS_OPT) -o $@ $^

# Rule to build q2 debug version
$(DEBUG_BIN_Q2): $(OBJ_Q2)
	$(CXX) $(CXXFLAGS_DEBUG) -o $@ $^

# Rule to build q2 optimized version
$(OPT_BIN_Q2): $(OBJ_Q2)
	$(CXX) $(CXXFLAGS_OPT) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS_DEBUG) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJ_Q1) $(OBJ_Q2) $(DEBUG_BIN_Q1) $(OPT_BIN_Q1) $(DEBUG_BIN_Q2) $(OPT_BIN_Q2)

# Phony targets
.PHONY: all clean
