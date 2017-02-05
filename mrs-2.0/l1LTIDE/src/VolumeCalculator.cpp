#include "VolumeCalculator.h"

double VolumeCalculator::volume(BSP_Tree const &tree) {
  int dimension = tree.root.enclosed_points.at(0)->dimension();

  return 2.0f;
}
