TEMPLATE = subdirs
SUBDIRS = common tests main
tests.depends = common
main.depends = common

#include(../common.pri)
