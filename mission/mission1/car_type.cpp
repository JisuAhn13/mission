#include "car_type.h"
#include "car_breakSystem.h"


void carType::selectCarType(int* stack,int answer)
{
    stack[CarType_Q] = answer;
    if (answer == 1)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (answer == 2)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (answer == 3)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void carType::question_car_type()
{
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}