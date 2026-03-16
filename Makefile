CXX=g++
CXXFLAGS=-std=c++23 -Werror -Wsign-conversion
SOURCES=DataProcessor.cpp TextAnalyzer.cpp SetOperations.cpp AlgorithmShowcase.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

all: demo
	./demo

demo: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: TestRunner.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
	./test

TestRunner.o: test.cpp DataProcessor.hpp TextAnalyzer.hpp SetOperations.hpp AlgorithmShowcase.hpp doctest.h
	$(CXX) $(CXXFLAGS) --compile test.cpp -o TestRunner.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

DataProcessor.o: DataProcessor.cpp DataProcessor.hpp

TextAnalyzer.o: TextAnalyzer.cpp TextAnalyzer.hpp

SetOperations.o: SetOperations.cpp SetOperations.hpp

AlgorithmShowcase.o: AlgorithmShowcase.cpp AlgorithmShowcase.hpp

main.o: main.cpp DataProcessor.hpp TextAnalyzer.hpp SetOperations.hpp AlgorithmShowcase.hpp

clean:
	rm -f *.o demo test