cmake_minimum_required(VERSION 3.19)
project(market_on_wheels)

set(CMAKE_CXX_STANDARD 14)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Build GraphViewerCpp
set(GRAPHVIEWERCPP_PATH lib/GraphViewerCpp)
add_subdirectory(${GRAPHVIEWERCPP_PATH})
include_directories(${GRAPHVIEWERCPP_PATH}/include)

file(GLOB SOURCE_FILES CONFIGURE_DEPENDS src/*.cpp src/*.h)
add_executable(market_on_wheels ${SOURCE_FILES})

target_link_libraries(market_on_wheels graphviewer)