TEMPLATE = subdirs
SUBDIRS = common tests main
tests.depends = common
main.depends = common

# ports
macx {
	QMAKE_CC = gcc-mp-4.6
	QMAKE_CXX = g++-mp-4.6
	QMAKE_LINK = g++-mp-4.6
	INCLUDEPATH += /opt/local/include
	LIBS += -L/opt/local/lib 
}
