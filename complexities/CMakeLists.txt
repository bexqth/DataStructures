add_library(
    complexities STATIC
        complexity_analyzer.cpp
)

target_include_directories(
    complexities PUBLIC ${PROJECT_SOURCE_DIR}
)

target_compile_features(
    complexities
    INTERFACE cxx_std_17
)

set_target_properties(
    complexities
    PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS        NO
)
