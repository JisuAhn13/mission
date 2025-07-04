#pragma once

#include <stdio.h>

#include "car_type.h"
#include "car_engine.h"
#include "car_breakSystem.h"
#include "car_steeringSytem.h"

class car {
public:
    void registerCarTpye(carType& type);
    void registerCarEngine(carEngine& engine);
    void registerCarBreaksystem(carBreakSystem& breakSystem);
    void registerCarSteeringSystem(carSteeringSystem& steeringSytem);

    int run;
    int assemble_step;
    carType type;
    carEngine engine;
    carBreakSystem brakeSystem;
    carSteeringSystem steeringSystem;
};