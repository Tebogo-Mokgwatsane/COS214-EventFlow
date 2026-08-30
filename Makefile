# Makefile for EventFlow – SkyPulse Airshow (COS214 Practical 3)

CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS  =

SOURCES  = $(wildcard *.cpp)
OBJECTS  = $(SOURCES:.cpp=.o)

TARGET   = eventflow

.PHONY: all clean run compile valgrind rebuild

all: $(TARGET)

compile: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built $(TARGET) successfully."

# Each .cpp produces a .o in the same directory
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the interactive program
run: $(TARGET)
	./$(TARGET)

# Memory-leak check
valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Remove build artefacts
clean:
	rm -f $(OBJECTS) $(TARGET)
	clear
	@echo "Cleaned."

# Rebuild from scratch
rebuild: clean all