add_executable(covidstats main.cpp)

if(MSVC)
    target_compile_options(covidstats PRIVATE /W4 /WX)
else()
    target_compile_options(covidstats PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

target_link_libraries(covidstats PUBLIC mylib)

install(TARGETS covidstats DESTINATION bin)
