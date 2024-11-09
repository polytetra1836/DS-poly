# Compiler
CXX = g++

# Target executable
TARGET = test

# Source files
SRCS = test.cpp

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -O2

# Build the executable
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean the build files
run: $(TARGET)
	time ./$(TARGET)
clean:
	rm -f $(TARGET)
report:
	xelatex report.tex