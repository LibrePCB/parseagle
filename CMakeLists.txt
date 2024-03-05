# CMake version configuration
cmake_minimum_required(VERSION 3.5...3.19)
if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# Define project
project(parseagle
    VERSION 0.2.0
    LANGUAGES CXX)

# If Qt version is not explicitly specified, automatically determine it
if(NOT PARSEAGLE_QT_MAJOR_VERSION)
    find_package(Qt NAMES Qt5 Qt6 REQUIRED COMPONENTS Core Xml)
    set(PARSEAGLE_QT_MAJOR_VERSION ${Qt_VERSION_MAJOR})
endif()
set(PARSEAGLE_QT "Qt${PARSEAGLE_QT_MAJOR_VERSION}")

# Use C++11 (Qt5) or C++17 (Qt6)
if(PARSEAGLE_QT_MAJOR_VERSION EQUAL 6)
    set(CMAKE_CXX_STANDARD 17)
else()
    set(CMAKE_CXX_STANDARD 11)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find required Qt packages
find_package(${PARSEAGLE_QT} REQUIRED COMPONENTS Core Xml)
message(STATUS "Building parseagle with Qt ${${PARSEAGLE_QT}_VERSION}")

# Export library
add_library(parseagle STATIC
    # Sources
    parseagle/board/board.cpp
    parseagle/board/contactref.cpp
    parseagle/board/designrules.cpp
    parseagle/board/element.cpp
    parseagle/board/param.cpp
    parseagle/board/signal.cpp
    parseagle/board/via.cpp
    parseagle/common/attribute.cpp
    parseagle/common/circle.cpp
    parseagle/common/dimension.cpp
    parseagle/common/domelement.cpp
    parseagle/common/frame.cpp
    parseagle/common/grid.cpp
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
    parseagle/deviceset/technology.cpp
    parseagle/library.cpp
    parseagle/package/hole.cpp
    parseagle/package/package.cpp
    parseagle/package/smtpad.cpp
    parseagle/package/thtpad.cpp
    parseagle/schematic/bus.cpp
    parseagle/schematic/instance.cpp
    parseagle/schematic/label.cpp
    parseagle/schematic/module.cpp
    parseagle/schematic/net.cpp
    parseagle/schematic/part.cpp
    parseagle/schematic/pinref.cpp
    parseagle/schematic/schematic.cpp
    parseagle/schematic/segment.cpp
    parseagle/schematic/sheet.cpp
    parseagle/symbol/pin.cpp
    parseagle/symbol/symbol.cpp

    # Headers
    parseagle/board/board.h
    parseagle/board/contactref.h
    parseagle/board/designrules.h
    parseagle/board/element.h
    parseagle/board/param.h
    parseagle/board/signal.h
    parseagle/board/via.h
    parseagle/common/attribute.h
    parseagle/common/circle.h
    parseagle/common/dimension.h
    parseagle/common/domelement.h
    parseagle/common/enums.h
    parseagle/common/frame.h
    parseagle/common/grid.h
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
    parseagle/deviceset/technology.h
    parseagle/library.h
    parseagle/package/hole.h
    parseagle/package/package.h
    parseagle/package/smtpad.h
    parseagle/package/thtpad.h
    parseagle/schematic/bus.h
    parseagle/schematic/instance.h
    parseagle/schematic/label.h
    parseagle/schematic/module.h
    parseagle/schematic/net.h
    parseagle/schematic/part.h
    parseagle/schematic/pinref.h
    parseagle/schematic/schematic.h
    parseagle/schematic/segment.h
    parseagle/schematic/sheet.h
    parseagle/symbol/pin.h
    parseagle/symbol/symbol.h
)
target_link_libraries(parseagle
    # Qt
    ${PARSEAGLE_QT}::Core
    ${PARSEAGLE_QT}::Xml
)
target_include_directories(parseagle INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

# Alias to namespaced variant
add_library(ParsEagle::ParsEagle ALIAS parseagle)
