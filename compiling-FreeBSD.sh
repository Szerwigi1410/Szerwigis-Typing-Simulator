#!/bin/sh

# Compile using Clang++
c++ -I/usr/local/include typing_simulator/*.cpp -L/usr/local/lib -lGL -lGLU -lglut -o game
