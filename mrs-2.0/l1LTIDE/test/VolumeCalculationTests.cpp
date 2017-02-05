#include "gtest/gtest.h"

#include "DensityTree/CGALTypeDefs.hpp"
#include "DensityTree/bsp.hpp"
#include "VolumeCalculator.h"

TEST(TestTest, ShouldAlwaysPass) {
  VolumeCalculator calc = VolumeCalculator();
  size_t num_points = 100;
  double size = 1.0;
  int dim = 2;

  CGAL::Random_points_in_cube_d<Point> gen(dim, size);
  std::vector<Point> points(num_points);

  for (int i = 0; i < num_points; i++) {
    points[i] = *gen++;
  }

  // Ugly! Must be a better way of doing this
  std::vector<Point *> points_ptrs(num_points);
  for (size_t i = 0; i < num_points; i++) {
    points_ptrs[i] = &points[i];
  }

  const BSP_Tree tree = BSP_Tree(points_ptrs, 0);
  double calculated_volume = calc.volume(tree);

  ASSERT_EQ(calculated_volume, 2.0f);
}
