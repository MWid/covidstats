add_executable(covidstats main.cpp)

target_link_libraries(covidstats PUBLIC casesrepo)

if(MSVC)
    target_compile_options(covidstats PRIVATE /W4 /WX)
else()
    target_compile_options(covidstats PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS covidstats DESTINATION bin)
