
#include "car.h"
#include "car_runtest.h"

void car::registerCarTpye(carType& type) {
    this->type = type;
}

void car::registerCarEngine(carEngine& engine) {
    this->engine = engine;
}

void car::registerCarBreaksystem(carBreakSystem& breakSystem) {
    this->brakeSystem = breakSystem;
}

void car::registerCarSteeringSystem(carSteeringSystem& steeringSytem){
    this->steeringSystem = steeringSytem;
}

void car::registerCarRunTest(carRunTest& runTest)
{
    this->runTest = runTest;
}
