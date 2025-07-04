#include <gmock/gmock.h>
#include "car.h"
#include "assemble.h"
using namespace testing;


class m2_UnitTest : public Test {
public:
	void SetUp() override {
		new_car->registerCarTpye(type);
		new_car->registerCarEngine(engine);
		new_car->registerCarBreaksystem(breakSystem);
		new_car->registerCarSteeringSystem(steeringSystem);
	}
	int stack[10];
	car* new_car= new car();
    carType type;
    carEngine engine;
    carBreakSystem breakSystem;
    carSteeringSystem steeringSystem;
	carRunTest* runTest = carRunTest::getInstance();
};

TEST_F(m2_UnitTest, printAllQuestions) {
	new_car->type.question_car_type();
	new_car->engine.question_car_engine();
	new_car->brakeSystem.question_carBreakSystem();
	new_car->steeringSystem.question_carSteeringSystem();
	runTest->question_carRunTest();
}

TEST_F(m2_UnitTest, carTypeTest) {
	EXPECT_EQ(SEDAN, type.selectCarType(stack, SEDAN));
	runTest->runProducedCar(stack);
	EXPECT_EQ(SUV, type.selectCarType(stack, SUV));
	runTest->runProducedCar(stack);
	EXPECT_EQ(TRUCK, type.selectCarType(stack, TRUCK));
	runTest->runProducedCar(stack);
}

TEST_F(m2_UnitTest, carEngineTest) {
	EXPECT_EQ(GM, engine.selectEngine(stack, GM));
	runTest->runProducedCar(stack);
	EXPECT_EQ(TOYOTA, engine.selectEngine(stack, TOYOTA));
	runTest->runProducedCar(stack);
	EXPECT_EQ(WIA, engine.selectEngine(stack, WIA));
	runTest->runProducedCar(stack);
}

TEST_F(m2_UnitTest, carBreakTest) {
	EXPECT_EQ(MANDO, breakSystem.selectBreakSystem(stack, MANDO));
	runTest->runProducedCar(stack);
	EXPECT_EQ(CONTINENTAL, breakSystem.selectBreakSystem(stack, CONTINENTAL));
	runTest->runProducedCar(stack);
	EXPECT_EQ(BOSCH_B, breakSystem.selectBreakSystem(stack, BOSCH_B));
	runTest->runProducedCar(stack);
}

TEST_F(m2_UnitTest, carsteeringTest) {
	EXPECT_EQ(BOSCH_S, steeringSystem.selectSteeringSystem(stack, BOSCH_S));
	runTest->runProducedCar(stack);
	EXPECT_EQ(MOBIS, steeringSystem.selectSteeringSystem(stack, MOBIS));
	runTest->runProducedCar(stack);
}

TEST_F(m2_UnitTest, comboTest) {
	EXPECT_EQ(TRUCK, type.selectCarType(stack, TRUCK));
	EXPECT_EQ(MANDO, breakSystem.selectBreakSystem(stack, MANDO));
	runTest->isValidCheck(stack);
	runTest->testProducedCar(stack);

	EXPECT_EQ(SEDAN, type.selectCarType(stack, SEDAN));
	EXPECT_EQ(CONTINENTAL, breakSystem.selectBreakSystem(stack, CONTINENTAL));
	runTest->isValidCheck(stack);
	runTest->testProducedCar(stack);

	EXPECT_EQ(SUV, type.selectCarType(stack, SUV));
	EXPECT_EQ(TOYOTA, engine.selectEngine(stack, TOYOTA));
	runTest->isValidCheck(stack);
	runTest->testProducedCar(stack);

	EXPECT_EQ(TRUCK, type.selectCarType(stack, TRUCK));
	EXPECT_EQ(WIA, engine.selectEngine(stack, WIA));
	runTest->isValidCheck(stack);
	runTest->testProducedCar(stack);


	type.selectCarType(stack, SEDAN);
	engine.selectEngine(stack, 4);
	breakSystem.selectBreakSystem(stack, MANDO);
	steeringSystem.selectSteeringSystem(stack, BOSCH_S);
	runTest->runProducedCar(stack);
	runTest->testProducedCar(stack);


}
TEST_F(m2_UnitTest, BOSCH_BbutNotMOBIS) {
	EXPECT_EQ(BOSCH_B, breakSystem.selectBreakSystem(stack, BOSCH_B));
	EXPECT_EQ(MOBIS, steeringSystem.selectSteeringSystem(stack, MOBIS));
	runTest->isValidCheck(stack);
	runTest->testProducedCar(stack);
}

TEST_F(m2_UnitTest, mixmode2) {

	type.selectCarType(stack, SEDAN);
	breakSystem.selectBreakSystem(stack, BOSCH_B);
	steeringSystem.selectSteeringSystem(stack, BOSCH_S);
	runTest->runProducedCar(stack);
}