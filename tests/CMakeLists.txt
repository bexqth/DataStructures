add_library(
    tests STATIC
        _details/console_output.cpp
        _details/console.cpp
        _details/test.cpp
)

target_include_directories(
    tests PUBLIC ${PROJECT_SOURCE_DIR}
)

target_compile_features(
    tests
    PUBLIC cxx_std_17
)

set_target_properties(
    tests
    PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS        NO
)
