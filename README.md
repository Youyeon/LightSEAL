# Modified Version of Microsoft SEAL 3.7.2

This repository provides two types of [SEAL](https://github.com/microsoft/SEAL/tree/3.7.2)

## Original version
- source files are placed in `native/origin/`
- to install this,
```PowerShell
    chmod 777 ./install_origin.sh
    sudo ./install_origin.sh
```
- Install path is `${home}/myseal_origin`

## Modified version (for SGX)
- source files are placed in `native/sgx/`
- (prerequisite) SGXSDK should be installed in `/opt/intel/sgxsdk`
- to install this,
```PowerShell
    cmake -S . -B build_sgx -DSEAL_BUILD_DEPS=OFF -DSEAL_USE_MSGSL=OFF -DSEAL_USE_ZSTD=OFF -DSEAL_USE_ZLIB=OFF -DSEAL_USE_CXX17=OFF -DSEAL_USE_INTRIN=OFF -DSEAL_USE_EXPLICIT_BZERO=OFF -DSEAL_SRC_PATH=sgx -DCMAKE_INSTALL_PREFIX=~/myseal_sgx
```
- Then modify `build_sgx/CMakeCache.txt` (CMakeLists.txt will be updated soon),
    - Set `CMAKE_CXX_FLAGS:STRING=-nostdinc -fvisibility=hidden -fpie -fstack-protector -I/opt/intel/sgxsdk/include -I/opt/intel/sgxsdk/include/libcxx -I/opt/intel/sgxsdk/include/tlibc -nostdinc++`
    - Set `CMAKE_C_FLAGS:STRING=-nostdinc -fvisibility=hidden -fpie -fstack-protector -I/opt/intel/sgxsdk/include -I/opt/intel/sgxsdk/include/libcxx -I/opt/intel/sgxsdk/include/tlibc`
    - Set `CMAKE_INSTALL_OLDINCLUDEDIR:PATH=/opt/intel/sgxsdk/include`
- continue,
```PowerShell
    cmake --build build_sgx
    sudo cmake --install build_sgx
```
- Install path is `${home}/myseal_sgx`

## Differences versus original version
- Add `set_coeff` method in PublicKey, SecretKey, Plaintext, Ciphertext and DynArray
- Add `ct_data`, `pt_data` struct in `ciphertext.h` and `plaintext.h`, respectively
- Remove features related to BFV scheme
- [Modified version] Remove features related to iostream, Serialization
- [Modified version] Remain functions only related to encryption&decryption