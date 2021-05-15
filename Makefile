# variables
CC := g++
SRCDIR := src
INCLUDEDIR := include
BUILDDIR := bin
CFLAG := -v
INC := -I include/alib -I lib/rang
APPNAME := alib
APPTESTNAME := alibTest
APPTESTDIR := test

.PHONY: all
all: testBuild testRun

.PHONY: build
build:
	${CC} ${CFLAG} ${SRCDIR}/${APPNAME}.cpp ${INC} -o ${BUILDDIR}/${APPNAME}.exe


.PHONY: run
run:


# Testing env
.PHONY: testBuild
testBuild:
	${CC} ${CFLAG} ${APPTESTDIR}/${APPTESTNAME}.cpp ${INC} -o ${BUILDDIR}/${APPTESTNAME}.exe

.PHONY: testRun
testRun:
	${BUILDDIR}/${APPTESTNAME}.exe

.PHONY: config
config:
	mkdir bin
	mkdir src

.PHONY: clean
clean:
	rm -r bin src

install:
	sudo cp include/alib/alib.hpp lib/rang/rang.hpp /usr/include
	echo Installed Alib to your system

uninstall:
	sudo rm /usr/include/alib.hpp /usr/include/rang.hpp
	echo "Removed Alib from your sytem"
