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
    parseagle/common/circle.cpp \
    parseagle/common/domelement.cpp \
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
    parseagle/symbol/pin.cpp \
    parseagle/symbol/symbol.cpp \

HEADERS += \
    parseagle/common/circle.h \
    parseagle/common/domelement.h \
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
    parseagle/symbol/pin.h \
    parseagle/symbol/symbol.h \

