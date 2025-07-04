#pragma once
#include <stdio.h>
#include "car_assemble_step.h"
#include "car_type.h"
#include "car_breakSystem.h"
#include "car_engine.h"
#include "car_steeringSytem.h"

class carRunTest {
public:
    carRunTest() = default;
    void question_carRunTest();
    void runProducedCar(int* stack);
    void testProducedCar(int* stack);

};
