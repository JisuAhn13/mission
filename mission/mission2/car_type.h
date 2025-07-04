#pragma once
#include "car_assemble_step.h"

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

class carType  {
public:
    carType() = default;
    int selectCarType(int* stack, int answer);
    void question_car_type();
private:
    int type;
};
