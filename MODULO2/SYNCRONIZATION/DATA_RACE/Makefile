# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17
LDFLAGS = -lpthread

# List of target executables
TARGETS = race \
          race_atomic \
          race_fixed \
          counter_thread \
          counter_thread_fixed \
          counter_thread_fixed2 \
          race_cout \
          race_cout_fixed

# Default target builds everything
all: $(TARGETS)

race: 1_race.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

race_atomic: 1_race_atomic.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

race_fixed: 1_race_fixed.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

counter_thread: 2_counter_thread.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

counter_thread_fixed: 2_counter_thread_fixed.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)	

counter_thread_fixed2: 2_counter_thread_fixed2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)	

race_cout: 3_race_resource_loop.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)		

race_cout_fixed: 3_race_resource_loop_fixed.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)	


# Clean up build artifacts
clean:
	rm -f $(TARGETS)

.PHONY: all clean
