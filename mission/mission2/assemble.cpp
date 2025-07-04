#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include "assemble.h"

int stack[10];
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
    // 숫자로 된 대답인지 확인
    char* checkNumber;
    int answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환
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
    // 처음으로 돌아가기
    if (answer == 0 && new_car.assemble_step == Run_Test)
    {
        new_car.assemble_step = CarType_Q;
        return 1;
    }

    // 이전으로 돌아가기
    if (answer == 0 && new_car.assemble_step >= 1)
    {
        new_car.assemble_step -= 1;
        return 1;
    }

    return 0;
}

int checkValidRange(char* checkNumber, car& new_car, int answer)
{
    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return 1;
    }

    if (new_car.assemble_step == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return 1;
    }
    return 0;
}

int isExit(char buf[100])
{
    if (!strcmp(buf, "exit"))
    {
        printf("바이바이\n");
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

    // 엔터 개행문자 제거
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
#endif