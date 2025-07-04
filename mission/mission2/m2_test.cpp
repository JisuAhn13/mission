#include <gmock/gmock.h>
using namespace testing;
class m2_fixture : public Test {
public:
	void SetUp() override {
		;
	}
};

TEST_F(m2_fixture, tc1) {
	EXPECT_EQ(1, 1);
}