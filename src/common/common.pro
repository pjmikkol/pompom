TEMPLATE = lib
CONFIG = console warn_on release staticlib
INCLUDEPATH += ../include
QMAKE_CXXFLAGS += -std=c++0x
TARGET = common
DESTDIR = ../../bin
SOURCES = pompom.cpp model.cpp encoder.cpp decoder.cpp

LIBS += -lpthread -lboost_system
