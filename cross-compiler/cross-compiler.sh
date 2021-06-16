#!/bin/bash

DownloadSources () {
    echo Downloading binutils ...
    curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.35.1.tar.gz
    echo Downloading gcc ...
    curl -O https://ftp.gnu.org/gnu/gcc/gcc-10.2.0/gcc-10.2.0.tar.gz
}

SetDirectories () {

    #Need to call CleanSources before

    mkdir binutils-build
    mkdir gcc-build
}

CleanSources () {
    rm binutils-2.35.1.tar.gz
    rm gcc-10.2.0.tar.gz
    rm -Rf binutils-build
    rm -Rf gcc-build
    rm -Rf binutils-2.35.1
    rm -Rf gcc-10.2.0
}
UnpackArchives () {
    echo Unpacking binutils-2.35.1.tar.gz ...
    tar xf binutils-2.35.1.tar.gz
    echo Unpacking gcc-10.2.0.tar.gz ...
    tar xf gcc-10.2.0.tar.gz
}

CleanSources
SetDirectories
DownloadSources
UnpackArchives