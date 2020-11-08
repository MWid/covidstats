add_library(mylib src/mylib.cpp)

target_include_directories(mylib INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")
