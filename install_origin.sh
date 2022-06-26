 #!/bin/bash
cmake -S . -B build_origin -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DSEAL_USE_EXPLICIT_BZERO=OFF -DSEAL_SRC_PATH=origin -DCMAKE_INSTALL_PREFIX=~/myseal_origin
if [ $? -eq 0 ]; then
    cmake --build build_origin
    if [ $? -eq 0 ]; then
    sudo cmake --install build_origin
    fi
fi


echo "end"