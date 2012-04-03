SOURCES = coderstest.cpp
DESTDIR = ../../bin
TARGET = codertests
CONFIG = console warn_on
QMAKE_CXXFLAGS += -std=c++0x

LIBS = -lboost_unit_test_framework
