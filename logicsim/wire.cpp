#include <set>
#include <iostream>
#include <string>
#include <sstream>

#include "wire.h"

Wire::Wire(int id, std::string name) : m_state('X'), m_name(name), m_id(id)
{
    
}

const char& Wire::getState() const
{
    return m_state;
}

std::string Wire::getName() const
{
    return m_name;
}

int Wire::getId() const
{
    return m_id;
}

std::string Wire::setState(char state, uint64_t time)
{
    if (state == m_state)
    {
        return "";
    }

    m_state = state;  // Update state first
    std::stringstream ss;
    ss << "W" << m_id << " is " << (m_state == '1' ? "high" : "low") << std::endl;
    return ss.str();
}

