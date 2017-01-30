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

#include "DensityTree/CGALTypeDefs.hpp"
#include <random>

enum class GeneratorType {
  Uniform,
  Normal
};

std::vector<Point> randNorm(unsigned int dim, size_t num_points, double mean = 0.0, double stddev = 1.0);
std::vector<Point> randUnif(int dim, int num_points);

std::vector<Point> randPoints(int dim, int num_points, GeneratorType gen = GeneratorType::Uniform);

Point randNormPoint(
    int dim,
    std::normal_distribution<double> &dist,
    std::mt19937_64 &mt);

int uni_rng(int num_points);

std::vector<Point> sample_d(std::vector<Point *> points, int n);
std::vector<Point> sample_d(std::vector<Point> points, int n);

