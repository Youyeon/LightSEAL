 #!/bin/bash
cmake -S . -B build_sgx -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DSEAL_USE_EXPLICIT_BZERO=OFF -DSEAL_SRC_PATH=sgx -DCMAKE_INSTALL_PREFIX=~/myseal_sgx
if [ $? -eq 0 ]; then
    cmake --build build_sgx
    if [ $? -eq 0 ]; then
    sudo cmake --install build_sgx
    fi
fi


echo "end"