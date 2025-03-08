#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <vector>
#include "wire.h"
#include "gate.h"
#include "heap.h"
#include "event.h"
#include <iostream>

class Circuit
{
public:
    Circuit();
    ~Circuit();

    bool parse(const char* fname);  // ✅ Parses the circuit file
    void run(std::ostream& os);     // ✅ Runs the simulation
    void startUml(std::ostream& os); // ✅ Begins UML output
    void endUml(std::ostream& os);   // ✅ Ends UML output
    void test();                     // ✅ Function that was missing

private:
    uint64_t m_current_time;
    std::vector<Wire*> m_wires;
    std::vector<Gate*> m_gates;
    
    Heap<Event*, EventLess> m_pq; // ✅ Priority queue for event handling

    bool advance(std::ostream& os); // ✅ Ensures `advance()` is declared properly
};

#endif
