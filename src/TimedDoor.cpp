// Copyright 2021 DBarinov
#include <ctime>
#include <string>

#include "TimedDoor.h"

void DoorTimeAdapter::Timeout() { door.DoorTimeOut(); }

TimedDoor::TimedDoor(int tout) {
    timeout = tout;
    state = false;
    adapter = new DoorTimeAdapter(*this);
}



void TimedDoor::lock() { state = false; }

void TimedDoor::unlock() {
    state = true;
    Timer timer;
    timer.sleeptime(timeout, adapter);
}

bool TimedDoor::isDoorOpened() { return state; }

void TimedDoor::DoorTimeOut() { throw std::string("close the door!"); }

void TimedDoor::throwState() {
    if (!state) {
        throw std::string("the door is closed!");
    }
    else {
        throw std::string("the door is opened!");
    }
}

void Timer::sleep(int t) {
    time_t start = time(nullptr);
    time_t end = start;
    while (end - start < t) {
        end = time(nullptr);
    }
}

void Timer::sleeptime(int t, TimerControl* timer_client) {
    sleep(t);
    timer_client->Timeout();
}
