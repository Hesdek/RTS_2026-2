# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17
LDFLAGS = -pthread

# Target executables
TARGETS = sequential multi_processing_singlecore multi_processing_multicore multi_threading

# Default target to build all executables
all: $(TARGETS)

# Rule for Sequential
sequential: Sequential.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule for Multi-Processing Single-Core
multi_processing_singlecore: Multi-Processing_SingleCore.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule for Multi-Processing Multi-Core
multi_processing_multicore: Multi-Processing_MultiCore.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Rule for Multi-Threading (requires pthread flags)
multi_threading: Multi-Threading.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

# Clean up build artifacts
clean:
	rm -f $(TARGETS)

.PHONY: all clean
