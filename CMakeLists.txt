cmake_minimum_required(VERSION 2.8)

project(sample-openmp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -g")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -pg")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -s -DNDEBUG -march=native")

find_package( OpenMP )
if (OPENMP_FOUND)
    # set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

# include path
include_directories(include)

file(GLOB HEADER_FILES include/*.hpp)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# executables
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
