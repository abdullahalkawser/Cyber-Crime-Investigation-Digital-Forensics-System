CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -Iinclude
TARGET = cyber_trace
SOURCES = main.cpp $(wildcard src/*.cpp)

all: $(TARGET)
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)
run: $(TARGET)
	./$(TARGET)
clean:
	rm -f $(TARGET)
