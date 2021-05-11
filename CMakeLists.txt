# CMake build system for ALIB

cmake_minimum_required(VERSION 3.12)
project(ALib VERSION 1.0.0)
if(WIN32)
    message("Heyyy")
elseif(UNIX)
    message("HOOOO")
endif()
