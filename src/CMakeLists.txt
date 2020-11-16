add_executable(covidstats main.cpp App.cpp)

find_package(nlohmann_json CONFIG REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)

find_path(BOOST_ALGORITHM_INCLUDE_DIRS "boost/algorithm/algorithm.hpp")

target_include_directories(covidstats PRIVATE ${BOOST_ALGORITHM_INCLUDE_DIRS})

target_link_libraries(covidstats PUBLIC casesrepo PRIVATE nlohmann_json::nlohmann_json Boost::program_options)

if(MSVC)
    target_compile_options(covidstats PRIVATE /W4 /WX)
else()
    target_compile_options(covidstats PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS covidstats DESTINATION bin)
