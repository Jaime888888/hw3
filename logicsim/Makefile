CXX = g++
CXXFLAGS = -Wall -g -std=c++11

# Default target
all: logicsim

# Compile the logic simulator
logicsim: logicsim.o circuit.o gate.o wire.o
	$(CXX) $(CXXFLAGS) -o logicsim logicsim.o circuit.o gate.o wire.o ../heap.h

logicsim.o: logicsim.cpp circuit.h gate.h wire.h event.h
	$(CXX) $(CXXFLAGS) -c logicsim.cpp

circuit.o: circuit.cpp circuit.h gate.h wire.h event.h ../heap.h
	$(CXX) $(CXXFLAGS) -c circuit.cpp

gate.o: gate.cpp gate.h wire.h event.h
	$(CXX) $(CXXFLAGS) -c gate.cpp

wire.o: wire.cpp wire.h
	$(CXX) $(CXXFLAGS) -c wire.cpp

# Clean up object files and executable
clean:
	rm -f logicsim logicsim.o circuit.o gate.o wire.o
