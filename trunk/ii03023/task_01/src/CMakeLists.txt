cmake_minimum_required(VERSION 3.10)
project(task_01_ii03021 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.h")


if(NOT TARGET task_01)
    add_executable(task_01 ${SOURCES} ${HEADERS})
else()
    
    target_sources(task_01 PRIVATE ${SOURCES} ${HEADERS})
endif()

if(MSVC)
    if(TARGET task_01)
        target_compile_options(task_01 PRIVATE /utf-8)
    endif()
endif()