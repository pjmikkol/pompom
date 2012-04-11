TEMPLATE = lib
CONFIG += staticlib
include(../../common.pri)
INCLUDEPATH += ../include
TARGET = common
SOURCES = pompom.cpp encoder.cpp decoder.cpp

LIBS += -lpthread -lboost_system
