#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

struct EventLess {
    bool operator()(const Event* e1, const Event* e2) const {
        return e1->time > e2->time; // Min-heap: earlier events have higher priority
    }
};

#endif
