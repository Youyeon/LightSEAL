cmake_minimum_required(VERSION 3.13)

project(
    test 
    VERSION 0.0.1
    LANGUAGES CXX C
)
add_executable(sealtest sealtest.cpp)

find_package(SEAL 3.7.2 EXACT REQUIRED PATHS ~/myseal/lib/cmake/SEAL-3.7)
#target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/includes)
target_link_libraries(sealtest SEAL::seal)