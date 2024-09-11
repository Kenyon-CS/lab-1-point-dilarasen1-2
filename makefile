# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = point_program

# Source files
SRCS = main.cpp Point.cpp Line.cpp

# Object files
OBJS = main.o Point.o Line.o

# Default target
all: $(TARGET)

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp into main.o
main.o: main.cpp Point.h Line.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile Point.cpp into Point.o
Point.o: Point.cpp Point.h
	$(CXX) $(CXXFLAGS) -c Point.cpp

# Rule to compile Line.cpp into Line.o
Line.o: Line.cpp Line.h Point.h
	$(CXX) $(CXXFLAGS) -c Line.cpp

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (targets that aren't actual files)
.PHONY: all clean
