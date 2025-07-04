#pragma once
#include "car_assemble_step.h"

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

class carEngine {
public:
    carEngine() = default;
    int selectEngine(int* stack, int answer);
    void question_car_engine();
};