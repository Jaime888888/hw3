CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Targets
all: llrec-test

# Compile the llrec-test executable
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.o llrec.o

# Compile object files
llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

# Clean up generated files
clean:
	rm -f llrec-test llrec-test.o llrec.o
