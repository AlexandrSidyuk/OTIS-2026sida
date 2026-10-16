cmake_minimum_required(VERSION 3.12)
project(Task01_ModelSimulations)

set(CMAKE_CXX_STANDARD 17)

add_executable(task_01
    main.cpp
    Model.h
    Model1_6.h Model1_6.cpp
    Model2_10.h Model2_10.cpp
    Model3_4.h Model3_4.cpp
)