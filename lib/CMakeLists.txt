add_library(mylib src/mylib.cpp)

target_include_directories(mylib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(MSVC)
    target_compile_options(mylib PRIVATE /W4 /WX)
else()
    target_compile_options(mylib PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
