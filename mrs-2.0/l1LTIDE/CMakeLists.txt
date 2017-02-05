# Created by the script cgal_create_CMakeLists
# This is the CMake script for compiling a set of CGAL applications.


set(PROJECT_NAME_STR l1-tide)
# Enable External project for gtest.
INCLUDE(ExternalProject)

project(DensityTree)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE) # Get around issue with CGAL not allowing config types other than build | release

set(CMAKE_VERBOSE_MAKEFILE 1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Wpedantic -g")  # enable C++11 standard

cmake_minimum_required(VERSION 2.8.11)

# CGAL and its components
find_package(CGAL QUIET COMPONENTS)

if (NOT CGAL_FOUND)

    message(STATUS "This project requires the CGAL library, and will not be compiled.")
    return()

endif ()

# include helper file
include(${CGAL_USE_FILE})

# Boost and its components
find_package(Boost REQUIRED)

if (NOT Boost_FOUND)

    message(STATUS "This project requires the Boost library, and will not be compiled.")

    return()

endif ()

#### Includes
include_directories(${PROJECT_SOURCE_DIR}/src)

# Creating entries for target: BSP_Tree
# ############################
MESSAGE("Headers are:" ${HEADERS} ${PROJECT_SOURCE_DIR})

add_executable(BSP_Tree hyperplane.cpp ${HEADERS} src/VolumeCalculator.cpp src/VolumeCalculator.h)


# Define all the binary space files
add_library(bsp.o STATIC src/bsp.cpp src/DensityTree/bsp.hpp)
target_link_libraries(BSP_Tree bsp.o)

# General utilities for dealing with cgal points
add_library(PointUtils.o STATIC src/DensityTree/PointUtils.hpp src/PointUtils.cpp)
target_link_libraries(BSP_Tree PointUtils.o)

add_library(VolumeUtils STATIC ${HEADERS} ${PROJECT_SOURCE_DIR}/src/VolumeCalculator.cpp ${PROJECT_SOURCE_DIR}/src/VolumeCalculator.h)
target_link_libraries(VolumeUtils ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} bsp.o)

add_to_cached_list(CGAL_EXECUTABLE_TARGETS BSP_Tree)

# Link the executable to CGAL and third-party libraries
target_link_libraries(BSP_Tree ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

###### Testing
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds
# the following targets: gtest, gtest_main, gmock
# and gmock_main
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gmock targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif ()

## Adding tests

enable_testing()

set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)
add_executable(point_generation ${TEST_DIR}/PointGenerationTest.cpp ${PROJECT_SOURCE_DIR}/src/DensityTree/PointUtils.hpp)
target_link_libraries(point_generation gtest gmock_main PointUtils.o)
add_test(NAME point_generation_test COMMAND point_generation)

add_executable(volume_calculation ${TEST_DIR}/VolumeCalculationTests.cpp ${PROJECT_SOURCE_DIR}/src/VolumeCalculator.h ${PROJECT_SOURCE_DIR}/src/DensityTree/PointUtils.hpp)
target_link_libraries(volume_calculation gtest gmock_main VolumeUtils ${CGAL_LIBRARIES} ${CGAL_3RD_PARTY_LIBRARIES} PointUtils.o)
add_test(NAME volume_calculation_test COMMAND volume_generation)
