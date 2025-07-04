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
    // ������, ���� ������, ���� �Ҵ� ������ private���� �����Ͽ� �ܺο����� ���� ������ �����ϴ�.
     carRunTest() {}
    carRunTest(const carRunTest&) = delete;
    carRunTest& operator=(const carRunTest&) = delete;
    ~carRunTest() {} // �Ҹ��ڵ� private���� ����
};
