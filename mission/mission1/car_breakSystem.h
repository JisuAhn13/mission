#pragma once
#include <stdio.h>
#include "car_question.h"

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};
class carBreakSystem {
public:
    carBreakSystem() = default;
    void selectBreakSystem(int* stack, int answer);
    void question_carBreakSystem();
private:
};
