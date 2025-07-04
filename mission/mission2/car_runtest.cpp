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
	printf("멋진 차량이 완성되었습니다.\n");
	printf("어떤 동작을 할까요?\n");
	printf("0. 처음 화면으로 돌아가기\n");
	printf("1. RUN\n");
	printf("2. Test\n");
}

void carRunTest::runProducedCar(int* stack)
{
	if (isValidCheck(stack) == false)
	{
		printf("자동차가 동작되지 않습니다\n");
	}
	else
	{
		if (stack[Engine_Q] == 4)
		{
			printf("엔진이 고장나있습니다.\n");
			printf("자동차가 움직이지 않습니다.\n");
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

			printf("자동차가 동작됩니다.\n");
		}
	}
}

void carRunTest::testProducedCar(int* stack)
{
	if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Sedan에는 Continental제동장치 사용 불가\n");
	}
	else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("SUV에는 TOYOTA엔진 사용 불가\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 WIA엔진 사용 불가\n");
	}
	else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 Mando제동장치 사용 불가\n");
	}
	else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
	{
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
	}
	else
	{
		printf("자동차 부품 조합 테스트 결과 : PASS\n");
	}
}