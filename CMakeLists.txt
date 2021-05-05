cmake_minimum_required(VERSION 3.19)
project(market_on_wheels)

set(CMAKE_CXX_STANDARD 14)

add_executable(market_on_wheels main.cpp src/market/Vehicle.cpp src/market/Vehicle.h src/market/Client.cpp src/market/Client.h)