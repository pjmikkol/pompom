TEMPLATE = app
SOURCES = main.cpp
TARGET = pompom
include(../../common.pri)

INCLUDEPATH += ../include

LIBS += -lboost_program_options -lpthread -L ../../bin -lcommon
