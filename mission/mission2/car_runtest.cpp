#include "car_runtest.h"

int carRunTest::isValidCheck(int* stack)
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
		return false;
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
		return false;
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
		return false;
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
		return false;
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
		return false;
	else
		return true;
}

void carRunTest::question_carRunTest()
{
	printf(CLEAR_SCREEN);
	printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
	printf("� ������ �ұ��?\n");
	printf("0. ó�� ȭ������ ���ư���\n");
	printf("1. RUN\n");
	printf("2. Test\n");
}

void carRunTest::runProducedCar(int* stack)
{
	if (isValidCheck(stack) == false)
	{
		printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
	}
	else
	{
		if (stack[Engine_Q] == 4)
		{
			printf("������ ���峪�ֽ��ϴ�.\n");
			printf("�ڵ����� �������� �ʽ��ϴ�.\n");
		}
		else
		{
			if (stack[CarType_Q] == 1)
				printf("Car Type : Sedan\n");
			if (stack[CarType_Q] == 2)
				printf("Car Type : SUV\n");
			if (stack[CarType_Q] == 3)
				printf("Car Type : Truck\n");
			if (stack[Engine_Q] == 1)
				printf("Engine : GM\n");
			if (stack[Engine_Q] == 2)
				printf("Engine : TOYOTA\n");
			if (stack[Engine_Q] == 3)
				printf("Engine : WIA\n");
			if (stack[brakeSystem_Q] == 1)
				printf("Brake System : Mando");
			if (stack[brakeSystem_Q] == 2)
				printf("Brake System : Continental\n");
			if (stack[brakeSystem_Q] == 3)
				printf("Brake System : Bosch\n");
			if (stack[SteeringSystem_Q] == 1)
				printf("SteeringSystem : Bosch\n");
			if (stack[SteeringSystem_Q] == 2)
				printf("SteeringSystem : Mobis\n");

			printf("�ڵ����� ���۵˴ϴ�.\n");
		}
	}
}

void carRunTest::testProducedCar(int* stack)
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Sedan���� Continental������ġ ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("SUV���� TOYOTA���� ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Truck���� WIA���� ��� �Ұ�\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Truck���� Mando������ġ ��� �Ұ�\n");
	}
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
		printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
	}
	else
	{
		printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
	}
}