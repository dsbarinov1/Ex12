// Copyright 2021 DBarinov
#ifndef INCLUDE_TIMEDDOOR_H_
#define INCLUDE_TIMEDDOOR_H_

class TimerControl;
class DoorState;
class TimedDoor;
class DoorTimeAdapter;
class Timer;


class TimerControl {
 public:
    virtual void Timeout() = 0;
};

class DoorState {
 public:
    virtual void lock() = 0;
    virtual void unlock() = 0;
    virtual bool isDoorOpened() = 0;
};

class TimedDoor : public DoorState {
 private:
    DoorTimeAdapter* adapter;
    int timeout;
    bool state;

 public:
    explicit TimedDoor(int);
    void lock();
    void unlock();
    bool isDoorOpened();
    void DoorTimeOut();
    void throwState();
};

class DoorTimeAdapter : public TimerControl {
 private:
    TimedDoor& door;

 public:
    explicit DoorTimeAdapter(TimedDoor& td_door) : door(td_door) {}
    void Timeout();
};

class Timer {
 private:
    TimerControl* client;
    void sleep(int);

 public:
    void sleeptime(int, TimerControl*);
};

#endif  // INCLUDE_TIMEDDOOR_H_
