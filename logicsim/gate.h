#ifndef GATE_H
#define GATE_H

#include <vector>
#include "event.h"
#include "wire.h"

class Gate
{
public:
    Gate(int num_inputs, Wire* output);
    virtual ~Gate();
    virtual Event* update(uint64_t) = 0;
    void wireInput(unsigned int, Wire*);

protected:
    Wire* m_output;
    std::vector<Wire*> m_inputs;
    uint32_t m_delay;
    char m_current_state;
};

class And2Gate : public Gate
{
public:
    And2Gate(Wire*, Wire*, Wire*);
    Event* update(uint64_t) override;
};

class Or2Gate : public Gate
{
public:
    Or2Gate(Wire*, Wire*, Wire*);
    Event* update(uint64_t) override;
};

class NotGate : public Gate // ✅ Added NotGate class
{
public:
    NotGate(Wire*, Wire*);
    Event* update(uint64_t) override;
};

#endif
