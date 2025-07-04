
#include "car.h"

void car::registerCarTpye(carType& type) {
    this->type = type;
}
void car::registerCarEngine(carEngine& engine) {
    this->engine = engine;
}
void car::registerCarBreaksystem(carBreakSystem& breakSystem) {
    this->brakeSystem = breakSystem;
}