include(FetchContent)

# Tags: https://github.com/doctest/doctest/tags
set(NEEDED_DOCTEST_VERSION "2.4.11")

find_package(doctest ${NEEDED_DOCTEST_VERSION} QUIET)

if (NOT doctest_FOUND)

    FetchContent_Declare(
        doctest
        GIT_REPOSITORY "https://github.com/doctest/doctest"
        GIT_TAG        v${NEEDED_DOCTEST_VERSION}
        GIT_SHALLOW    TRUE
    )

    FetchContent_MakeAvailable(doctest)

    # include the doctest module that contains doctest_discover_tests
    list(APPEND CMAKE_MODULE_PATH ${doctest_SOURCE_DIR}/scripts/cmake)

endif()

# this needs to be called for the doctest_discover_tests function to work
include(doctest)

add_executable(testrunner main.cpp)

target_sources(testrunner
    PUBLIC
        FILE_SET CXX_MODULES
        FILES
            alphabet_tests.cpp
            math_tests.cpp
            substitution_tests.cpp
            text_tests.cpp
)

target_link_libraries(testrunner
    PRIVATE
        doctest::doctest
        cipher::cipher
)

doctest_discover_tests(testrunner)
