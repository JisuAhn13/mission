#pragma once

#include <stdio.h>

#include "car_type.h"
#include "car_engine.h"
#include "car_breakSystem.h"
#include "car_steeringSytem.h"
#include "car_runtest.h"


class car {
public:
    virtual void registerCarTpye(carType& type);
    virtual void registerCarEngine(carEngine& engine);
    virtual void registerCarBreaksystem(carBreakSystem& breakSystem);
    virtual void registerCarSteeringSystem(carSteeringSystem& steeringSytem);
    virtual void registerCarRunTest(carRunTest& runTest);

    int assemble_step;
    carType type;
    carEngine engine;
    carBreakSystem brakeSystem;
    carSteeringSystem steeringSystem;
    carRunTest runTest;
};