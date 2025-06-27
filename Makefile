CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = simulation
SOURCES = main.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(SFML_LIBS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: clean run 