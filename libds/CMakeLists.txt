add_library(
    ds INTERFACE
)

target_include_directories(
    ds INTERFACE ${PROJECT_SOURCE_DIR}
)

target_compile_features(
    ds
    INTERFACE cxx_std_17
)

set_target_properties(
    ds
    PROPERTIES
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS        NO
)
