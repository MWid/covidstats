add_library(casesrepo src/RKICasesRepository.cpp)

find_package(cpprestsdk CONFIG REQUIRED)

target_include_directories(casesrepo INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(casesrepo PRIVATE cpprestsdk::cpprest cpprestsdk::cpprestsdk_zlib_internal cpprestsdk::cpprestsdk_brotli_internal)

if(MSVC)
    target_compile_options(casesrepo PRIVATE /W4 /WX)
else()
    target_compile_options(casesrepo PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
