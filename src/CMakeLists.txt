add_executable(covidstats main.cpp)

find_package(nlohmann_json CONFIG REQUIRED)

target_link_libraries(covidstats PUBLIC casesrepo PRIVATE nlohmann_json::nlohmann_json)

if(MSVC)
    target_compile_options(covidstats PRIVATE /W4 /WX)
else()
    target_compile_options(covidstats PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS covidstats DESTINATION bin)
