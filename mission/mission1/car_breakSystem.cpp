#include "car_breakSystem.h"

void carBreakSystem::selectBreakSystem(int* stack, int answer)
{
	stack[brakeSystem_Q] = answer;
	if (answer == 1)
		printf("MANDO 제동장치를 선택하셨습니다.\n");
	if (answer == 2)
		printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
	if (answer == 3)
		printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void carBreakSystem::question_carBreakSystem()
{
	printf(CLEAR_SCREEN);
	printf("어떤 제동장치를 선택할까요?\n");
	printf("0. 뒤로가기\n");
	printf("1. MANDO\n");
	printf("2. CONTINENTAL\n");
	printf("3. BOSCH\n");
}