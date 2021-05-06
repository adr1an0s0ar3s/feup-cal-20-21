cmake_minimum_required(VERSION 3.19)
project(market_on_wheels)

set(CMAKE_CXX_STANDARD 14)

add_executable(market_on_wheels
        main.cpp

        src/market/Client.cpp
        src/market/Client.h
        src/market/Order.cpp
        src/market/Order.h
        src/market/Product.cpp
        src/market/Product.h
        src/market/Stock.cpp
        src/market/Stock.h
        src/market/Supplier.cpp
        src/market/Supplier.h
        src/market/Vehicle.cpp
        src/market/Vehicle.h

        src/util/Time.cpp
        src/util/Time.h)