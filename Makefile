# variables
CC := g++
SRCDIR := src
INCLUDEDIR := include
BUILDDIR := bin
CFLAG := -v
INC := -I include/alib -I lib
APPNAME := alib
APPTESTNAME := alibTest
APPTESTDIR := test

.PHONY: all
all: build run

.PHONY: build
buidl:
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
