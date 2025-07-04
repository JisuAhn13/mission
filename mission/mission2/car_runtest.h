#pragma once
#include <stdio.h>
#include "car_assemble_step.h"
#include "car_type.h"
#include "car_breakSystem.h"
#include "car_engine.h"
#include "car_steeringSytem.h"

class carRunTest {

public:
    void question_carRunTest();
    void runProducedCar(int* stack);
    void testProducedCar(int* stack);
    int isValidCheck(int* stack);
    static carRunTest* getInstance() {
        if (carRun == nullptr) {
            carRun = new carRunTest();
        }
        return carRun;
    }
private:
    static carRunTest* carRun;
    // 생성자, 복사 생성자, 복사 할당 연산자 private으로 선언하여 외부에서의 직접 생성을 막습니다.
     carRunTest() {}
    carRunTest(const carRunTest&) = delete;
    carRunTest& operator=(const carRunTest&) = delete;
    ~carRunTest() {} // 소멸자도 private으로 선언
};
