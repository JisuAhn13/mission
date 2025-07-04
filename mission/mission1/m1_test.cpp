#include <gmock/gmock.h>
using namespace testing;
class m1_fixture : public Test {
	;
};

TEST(m1, tc1) {
	EXPECT_EQ(1, 1);
}