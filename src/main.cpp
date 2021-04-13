// Copyright 2021 DBarinov

#include <iostream>
#include "TimedDoor.h"

int main() {
    TimedDoor test_door(10);
    test_door.lock();
    test_door.unlock();
}
