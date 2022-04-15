#!/bin/bash

cmake -S . -B build -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DCMAKE_INSTALL_PREFIX=~/myseal
cmake --build build
sudo cmake --install build

sudo cp ~/myseal/lib/libseal-3.7.a /opt/intel/sgxsdk/lib64/
sudo cp -r ~/myseal/include/SEAL-3.7/seal /opt/intel/sgxsdk/include