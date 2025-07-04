#pragma once
#include "car_question.h"

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
