SOURCES = coderstest.cpp
TARGET = codertests
include(../../common.pri)
CONFIG = console warn_on
QMAKE_CXXFLAGS += -g

LIBS = -lboost_unit_test_framework
