add_library(cipher)
add_library(cipher::cipher ALIAS cipher)

target_sources(cipher
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            alphabet.cpp
            cipher.cpp
            math.cpp
            substitution.cpp
            text.cpp
)

target_compile_features(cipher PUBLIC cxx_std_23)
