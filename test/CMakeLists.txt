include(FetchContent)
include(GoogleTest)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE gtest_main
    PUBLIC casesrepo)

if(MSVC)
    target_compile_options(tests PRIVATE /W4 /WX)
else()
    target_compile_options(tests PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

gtest_discover_tests(tests)
