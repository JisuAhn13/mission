#pragma once
#include "car_question.h"

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

class carEngine {
public:
    carEngine() = default;
    void selectEngine(int* stack, int answer);
    void question_car_engine();
};