#!/usr/bin/env bash
##
## EPITECH PROJECT, 2020
##
## File description:
##
##

if [ -v $1 ]
then
    set "build"
fi

if [ $1 = "build" ]
then
    mkdir build; cd build; cmake ..; make; cp bomberman ..
elif [ $1 = "clean" ]
then
    rm -r build
    rm bomberman
    rm src/config.h
elif [ $1 = "-h" ]
then
    echo "./compile.sh build for build"
    echo "./compile.sh clean for clean"
fi
