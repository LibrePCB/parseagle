# CMake version configuration
cmake_minimum_required(VERSION 3.5...3.19)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Define project
project(parseagle
    VERSION 0.2.0
    LANGUAGES CXX)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required Qt packages
find_package(Qt5 5.2.0 COMPONENTS Core Xml REQUIRED)

# Export library
add_library(parseagle STATIC
    # Sources
    parseagle/common/circle.cpp
    parseagle/common/domelement.cpp
    parseagle/common/polygon.cpp
    parseagle/common/rectangle.cpp
    parseagle/common/rotation.cpp
    parseagle/common/text.cpp
    parseagle/common/vertex.cpp
    parseagle/common/wire.cpp
    parseagle/deviceset/connection.cpp
    parseagle/deviceset/device.cpp
    parseagle/deviceset/deviceset.cpp
    parseagle/deviceset/gate.cpp
    parseagle/library.cpp
    parseagle/package/hole.cpp
    parseagle/package/package.cpp
    parseagle/package/smtpad.cpp
    parseagle/package/thtpad.cpp
    parseagle/symbol/pin.cpp
    parseagle/symbol/symbol.cpp

    # Headers
    parseagle/common/circle.h
    parseagle/common/domelement.h
    parseagle/common/point.h
    parseagle/common/polygon.h
    parseagle/common/rectangle.h
    parseagle/common/rotation.h
    parseagle/common/text.h
    parseagle/common/vertex.h
    parseagle/common/wire.h
    parseagle/deviceset/connection.h
    parseagle/deviceset/device.h
    parseagle/deviceset/deviceset.h
    parseagle/deviceset/gate.h
    parseagle/library.h
    parseagle/package/hole.h
    parseagle/package/package.h
    parseagle/package/smtpad.h
    parseagle/package/thtpad.h
    parseagle/symbol/pin.h
    parseagle/symbol/symbol.h
)
target_link_libraries(parseagle
    # Qt
    Qt5::Core
    Qt5::Xml
)
target_include_directories(parseagle INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# Alias to namespaced variant
add_library(ParsEagle::ParsEagle ALIAS parseagle)
