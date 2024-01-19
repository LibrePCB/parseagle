#-------------------------------------------------
#
# Project created 2017-10-11
#
#-------------------------------------------------

TEMPLATE = lib
TARGET = parseagle

# Use common project definitions
include(../../common.pri)

QT -= gui widgets

CONFIG -= app_bundle
CONFIG += staticlib

SOURCES += \
    parseagle/board/board.cpp \
    parseagle/board/contactref.cpp \
    parseagle/board/designrules.cpp \
    parseagle/board/element.cpp \
    parseagle/board/param.cpp \
    parseagle/board/signal.cpp \
    parseagle/board/via.cpp \
    parseagle/common/attribute.cpp \
    parseagle/common/circle.cpp \
    parseagle/common/dimension.cpp \
    parseagle/common/domelement.cpp \
    parseagle/common/frame.cpp \
    parseagle/common/grid.cpp \
    parseagle/common/polygon.cpp \
    parseagle/common/rectangle.cpp \
    parseagle/common/rotation.cpp \
    parseagle/common/text.cpp \
    parseagle/common/vertex.cpp \
    parseagle/common/wire.cpp \
    parseagle/deviceset/connection.cpp \
    parseagle/deviceset/device.cpp \
    parseagle/deviceset/deviceset.cpp \
    parseagle/deviceset/gate.cpp \
    parseagle/library.cpp \
    parseagle/package/hole.cpp \
    parseagle/package/package.cpp \
    parseagle/package/smtpad.cpp \
    parseagle/package/thtpad.cpp \
    parseagle/schematic/bus.cpp \
    parseagle/schematic/instance.cpp \
    parseagle/schematic/label.cpp \
    parseagle/schematic/module.cpp \
    parseagle/schematic/net.cpp \
    parseagle/schematic/part.cpp \
    parseagle/schematic/pinref.cpp \
    parseagle/schematic/schematic.cpp \
    parseagle/schematic/segment.cpp \
    parseagle/schematic/sheet.cpp \
    parseagle/symbol/pin.cpp \
    parseagle/symbol/symbol.cpp \

HEADERS += \
    parseagle/board/board.h \
    parseagle/board/contactref.h \
    parseagle/board/designrules.h \
    parseagle/board/element.h \
    parseagle/board/param.h \
    parseagle/board/signal.h \
    parseagle/board/via.h \
    parseagle/common/attribute.h \
    parseagle/common/circle.h \
    parseagle/common/dimension.h \
    parseagle/common/domelement.h \
    parseagle/common/enums.h \
    parseagle/common/frame.h \
    parseagle/common/grid.h \
    parseagle/common/point.h \
    parseagle/common/polygon.h \
    parseagle/common/rectangle.h \
    parseagle/common/rotation.h \
    parseagle/common/text.h \
    parseagle/common/vertex.h \
    parseagle/common/wire.h \
    parseagle/deviceset/connection.h \
    parseagle/deviceset/device.h \
    parseagle/deviceset/deviceset.h \
    parseagle/deviceset/gate.h \
    parseagle/library.h \
    parseagle/package/hole.h \
    parseagle/package/package.h \
    parseagle/package/smtpad.h \
    parseagle/package/thtpad.h \
    parseagle/schematic/bus.h \
    parseagle/schematic/instance.h \
    parseagle/schematic/label.h \
    parseagle/schematic/module.h \
    parseagle/schematic/net.h \
    parseagle/schematic/part.h \
    parseagle/schematic/pinref.h \
    parseagle/schematic/schematic.h \
    parseagle/schematic/segment.h \
    parseagle/schematic/sheet.h \
    parseagle/symbol/pin.h \
    parseagle/symbol/symbol.h \

