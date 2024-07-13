cmake_minimum_required(VERSION 3.10)
project(thingy C)
set(CMAKE_C_STANDARD 99)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

find_package(SDL2 REQUIRED)

include_directories(
	src/
	lib/
)

include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SRCS
	src/*.c
	lib/*.c
)

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})
