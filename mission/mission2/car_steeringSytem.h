#pragma once
#include <stdio.h>
#include "car_assemble_step.h"

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

class carSteeringSystem {
public:
    carSteeringSystem() = default;
    void selectSteeringSystem(int* stack, int answer);
    void question_carSteeringSystem();
};
