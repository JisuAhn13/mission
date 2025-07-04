#pragma once
#include <stdio.h>
#include "car_question.h"

#define CLEAR_SCREEN_CAR_TYPE "\033[H\033[2J"
enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

class carType  {
public:
    carType() = default;
    void selectCarType(int* stack, int answer);
    void question_car_type();
private:
    int type;
};
