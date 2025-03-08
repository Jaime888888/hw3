#ifndef EVENT_H
#define EVENT_H

#include <cstdint>

struct Event
{
    uint64_t time;
    struct Wire* wire;
    char state;
};

struct EventLess
{
    bool operator()(const Event* lhs, const Event* rhs) const
    {
        return lhs->time > rhs->time; // Min-heap: earlier events have higher priority
    }
};

#endif
