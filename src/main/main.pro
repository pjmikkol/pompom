TEMPLATE = app
SOURCES = main.cpp
TARGET = pompom
CONFIG = console warn_on release
INCLUDEPATH += ../include
QMAKE_CXXFLAGS += -std=c++0x
DESTDIR = ../../bin

LIBS += -lboost_program_options -lpthread -L ../../bin -lcommon
