#pragma once

#include <stdio.h>

#include "car_type.h"

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};
class car {
public:
    void registerCarTpye(carType& type) {
        this->type = type;
    }
    int assemble_step;
    int engine;
    int brakeSystem;
    int steeringSystem;
    int run;
    carType type;
};