#include <gtest/gtest.h>
#include "two_sum.h"

TEST(TwoSum, twoSum)
{
    Solution2 s;
    std::vector<int> v1{2,7,11,15};
    ASSERT_THAT(s.twoSum(v1, 9), testing::ContainerEq(std::vector<int>{0,1}));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}