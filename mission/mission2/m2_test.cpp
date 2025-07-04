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
		new_car->registerCarRunTest(runtest);
	}
	int stack[10];
	car* new_car= new car();
    carType type;
    carEngine engine;
    carBreakSystem breakSystem;
    carSteeringSystem steeringSystem;
    carRunTest runtest;
};

TEST_F(m2_UnitTest, carTypeTest) {
	EXPECT_EQ(SEDAN, type.selectCarType(stack, SEDAN));
	EXPECT_EQ(SUV, type.selectCarType(stack, SUV));
	EXPECT_EQ(TRUCK, type.selectCarType(stack, TRUCK));
}

TEST_F(m2_UnitTest, carEngineTest) {
	EXPECT_EQ(GM, engine.selectEngine(stack, GM));
	EXPECT_EQ(TOYOTA, engine.selectEngine(stack, TOYOTA)); 
	EXPECT_EQ(WIA, engine.selectEngine(stack, WIA));
}

TEST_F(m2_UnitTest, carBreakTest) {
	EXPECT_EQ(MANDO, breakSystem.selectBreakSystem(stack, MANDO));
	EXPECT_EQ(CONTINENTAL, breakSystem.selectBreakSystem(stack, CONTINENTAL));
	EXPECT_EQ(BOSCH_B, breakSystem.selectBreakSystem(stack, BOSCH_B));
}

TEST_F(m2_UnitTest, carsteeringTest) {
	EXPECT_EQ(BOSCH_S, steeringSystem.selectSteeringSystem(stack, BOSCH_S));
	EXPECT_EQ(MOBIS, steeringSystem.selectSteeringSystem(stack, MOBIS));
}

TEST_F(m2_UnitTest, carRunTest) {
	runtest.runProducedCar(stack);
}
