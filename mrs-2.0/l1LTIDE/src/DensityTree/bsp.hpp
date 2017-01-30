/*
* copyright (c) 2016 dillon george
*
* this file is part of mrs, a c++ class library for statistical set processing.
*
* mrs is free software; you can redistribute it and/or modify
* it under the terms of the gnu general public license as published by
* the free software foundation; either version 3 of the license, or (at
* your option) any later version.
*
* this program is distributed in the hope that it will be useful, but
* without any warranty; without even the implied warranty of
* merchantability or fitness for a particular purpose.  see the gnu
* general public license for more details.
*
* you should have received a copy of the gnu general public license
* along with this program; if not, write to the free software
* foundation, inc., 675 mass ave, cambridge, ma 02139, usa.
*/

/*! \file
\brief
*/

#pragma once

#include <queue>
#include <tuple>
#include "DensityTree/CGALTypeDefs.hpp"
#include "DensityTree/PointUtils.hpp"

class BSP_node {

 private:
  void generate_hyperplane(std::vector<Point *> points);

 public:
  BSP_node *left = nullptr;
  BSP_node *right = nullptr;
  Plane hyperplane;

  int num_points = 0;
  std::vector<Point *> enclosed_points;
//  void add_points(std::vector<Point *>, int remaining_splits);

//  void print_tree(int max_depth = -1, int indent_level = 0);

  int Max_Num();
  int Min_Num();

  BSP_node() {};

  BSP_node(Plane h) {
    hyperplane = h;
  }

  BSP_node(std::vector<Point *> points) {
    // Defines the depth of the tree
    enclosed_points = points;
    num_points = points.size();

  };

  void print_tree(int max_depth, int indent_level);

  std::tuple<BSP_node *, BSP_node *> split();

};

class BSP_Tree {
 private:

 public:
  BSP_Tree(std::vector<Point *> points, int min_points) {
    root = BSP_node(points);

    BSP_node *current_node = &root;

    auto comparator = [](BSP_node *l, BSP_node *r) { return l->num_points < r->num_points; };
    std::priority_queue<BSP_node *, std::vector<BSP_node *>, decltype(comparator)> node_queue(comparator);

    // Continue to split until largest node has less than specified number of points
    while (current_node->num_points > min_points) {

      std::tuple<BSP_node *, BSP_node *> split_nodes = current_node->split();
      BSP_node *left = std::get<0>(split_nodes);
      BSP_node *right = std::get<1>(split_nodes);

      node_queue.push(left);
      node_queue.push(right);

      current_node = node_queue.top();
//      std::cout << "Current node count = " << current_node->num_points << std::endl;
      node_queue.pop();
    }

//    while (! node_queue.empty()) {
//      std::cout << "count: " << node_queue.top()->num_points << std::endl;
//      node_queue.pop();
//    }
  }

  BSP_node root;
};



