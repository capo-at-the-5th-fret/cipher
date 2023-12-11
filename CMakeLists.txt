cmake_minimum_required(VERSION 3.28)

project(cipher LANGUAGES CXX)

add_executable(cipher main.cpp)

target_sources(cipher
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            #caesar.cpp
            cipher.cpp
            substitution.cpp
            math.cpp
)

target_compile_features(cipher PUBLIC cxx_std_23)