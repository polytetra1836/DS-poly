# Makefile for List project

# Compiler
CXX = g++

# Target executable
TARGET = List

# Source files
SRCS = List.cpp

# Compiler flags
CXXFLAGS = -std=c++20 -Wall

# Build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean the build files
clean:
	rm -f $(TARGET)
report:
	xelatex report.tex