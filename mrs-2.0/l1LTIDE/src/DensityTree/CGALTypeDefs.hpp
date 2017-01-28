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

#include <CGAL/Cartesian_d.h>
#include <CGAL/Kernel_d/Hyperplane_d.h>
#include <CGAL/point_generators_d.h>

typedef CGAL::Cartesian_d<double>                           Kd;
typedef Kd::Point_d                                         Point;
typedef Kd::Hyperplane_d                                    Plane;
