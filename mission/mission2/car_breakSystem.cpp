#include "car_breakSystem.h"

int carBreakSystem::selectBreakSystem(int* stack, int answer)
{
	stack[brakeSystem_Q] = answer;
	if (answer == 1)
		printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 2)
		printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
	if (answer == 3)
		printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
	return answer;
}

void carBreakSystem::question_carBreakSystem()
{
	printf(CLEAR_SCREEN);
	printf("� ������ġ�� �����ұ��?\n");
	printf("0. �ڷΰ���\n");
	printf("1. MANDO\n");
	printf("2. CONTINENTAL\n");
	printf("3. BOSCH\n");
}