#include "gtest/gtest.h"

#include "DensityTree/PointUtils.hpp"

TEST(UniformPointTest, GeneratesCorrectNumPoints) {
    std::vector<Point> uniformTestPoints = randUnif(100, 100);
    for(int i = 0; i < uniformTestPoints.size(); i++) {
        Point p = uniformTestPoints[i];
        EXPECT_EQ(p.dimension(), 100);
    }
    ASSERT_EQ(uniformTestPoints.size(), 100);
}
