 #!/bin/bash

# cmake -S . -B build -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DSEAL_USE_EXPLICIT_BZERO=OFF -DCMAKE_INSTALL_PREFIX=~/myseal
if [ $? -eq 0 ]; then
    cmake --build build
    if [ $? -eq 0 ]; then
    sudo cmake --install build
    fi
fi

#sudo cp ~/myseal/lib/libseal-3.7.a /opt/intel/sgxsdk/lib64/
#sudo cp -r ~/myseal/include/SEAL-3.7/seal /opt/intel/sgxsdk/include

echo "end"