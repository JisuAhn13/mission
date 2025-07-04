

#include "assemble.h"

int main()
{
    car new_car;
    char buf[100];
    new_car.assemble_step = CarType_Q;

    registAssemblePart(new_car);
    while (1)
    {
        forword_next_assemble_step(new_car);
        getUserInput(buf);

        if (isExit(buf)) break;
        if(processAssembleLine(buf, new_car)==1) continue;
    }
}

int processAssembleLine(char  buf[100], car& new_car)
{
    // ���ڷ� �� ������� Ȯ��
    char* checkNumber;
    int answer = strtol(buf, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ
    if (checkValidRange(checkNumber, new_car, answer))return 1;
    if (checkUserWantFirstStage(answer, new_car)) return 1;
    startAssembleAccordingToAseembleStep(new_car, answer);
    return 0;
}

 void startAssembleAccordingToAseembleStep(car& new_car, int answer)
{

    if (new_car.assemble_step == CarType_Q)
    {
        new_car.type.selectCarType(stack, answer);
        delay(800);
        new_car.assemble_step = Engine_Q;
    }
    else if (new_car.assemble_step == Engine_Q)
    {
        new_car.engine.selectEngine(stack, answer);
        delay(800);
        new_car.assemble_step = brakeSystem_Q;
    }
    else if (new_car.assemble_step == brakeSystem_Q)
    {
        new_car.brakeSystem.selectBreakSystem(stack, answer);
        delay(800);
        new_car.assemble_step = SteeringSystem_Q;
    }
    else if (new_car.assemble_step == SteeringSystem_Q)
    {
        new_car.steeringSystem.selectSteeringSystem(stack, answer);
        delay(800);
        new_car.assemble_step = Run_Test;
    }
    else if (new_car.assemble_step == Run_Test && answer == 1)
    {
        new_car.runTest.runProducedCar(stack);
        delay(2000);
    }
    else if (new_car.assemble_step == Run_Test && answer == 2)
    {
        printf("Test...\n");
        delay(1500);
        new_car.runTest.testProducedCar(stack);
        delay(2000);
    }
}

int checkUserWantFirstStage(int answer, car& new_car)
{
    // ó������ ���ư���
    if (answer == 0 && new_car.assemble_step == Run_Test)
    {
        new_car.assemble_step = CarType_Q;
        return 1;
    }

    // �������� ���ư���
    if (answer == 0 && new_car.assemble_step >= 1)
    {
        new_car.assemble_step -= 1;
        return 1;
    }

    return 0;
}

int checkValidRange(char* checkNumber, car& new_car, int answer)
{
    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(800);
        return 1;
    }
    return 0;
}

int isExit(char buf[100])
{
    if (!strcmp(buf, "exit"))
    {
        printf("���̹���\n");
        {  return 1; };
    }
    return 0;
}

void registAssemblePart(car& new_car)
{
    carType type;
    carEngine engine;
    carBreakSystem breakSystem;
    carSteeringSystem steeringSystem;
    carRunTest runtest;
    new_car.registerCarTpye(type);
    new_car.registerCarEngine(engine);
    new_car.registerCarBreaksystem(breakSystem);
    new_car.registerCarSteeringSystem(steeringSystem);
    new_car.registerCarRunTest(runtest);
}
void getUserInput(char  buf[100])
{
    printf("===============================\n");

    printf("INPUT > ");
    fgets(buf, sizeof(buf), stdin);

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

void forword_next_assemble_step(car& new_car)
{
    if (new_car.assemble_step == CarType_Q)
    {
        new_car.type.question_car_type();
    }
    else if (new_car.assemble_step == Engine_Q)
    {
        new_car.engine.question_car_engine();
    }
    else if (new_car.assemble_step == brakeSystem_Q)
    {
        new_car.brakeSystem.question_carBreakSystem();
    }
    else if (new_car.assemble_step == SteeringSystem_Q)
    {
        new_car.steeringSystem.question_carSteeringSystem();
    }
    else if (new_car.assemble_step == Run_Test)
    {
        new_car.runTest.question_carRunTest();
    }
}
#if 0
int isValidCheck()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        return false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (isValidCheck() == false)
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
#endif

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}