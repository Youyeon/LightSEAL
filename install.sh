 #!/bin/bash
cmake -S . -B build3 -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DSEAL_USE_EXPLICIT_BZERO=OFF -DCMAKE_INSTALL_PREFIX=~/myseal_setparms
if [ $? -eq 0 ]; then
    cmake --build build3
    if [ $? -eq 0 ]; then
    sudo cmake --install build3
    fi
fi


echo "end"