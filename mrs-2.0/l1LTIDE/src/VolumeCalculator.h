
#ifndef DENSITYTREE_VOLUME_CALCULATION_H
#define DENSITYTREE_VOLUME_CALCULATION_H

#include <CGAL/

#include <DensityTree/bsp.hpp>

/**
 * Calculates volume of a d-dimensional volume
 */
class VolumeCalculator {
 public:
  double volume(BSP_Tree const &tree);

 private:

};

#endif //DENSITYTREE_VOLUME_CALCULATION_H
