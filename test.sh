#!/bin/bash

cd premake
./gmake.sh
cd gmake
make
build/Debug/bitbuf_test
