add_executable(covidstats main.cpp)

target_link_libraries(covidstats PUBLIC mylib)

install(TARGETS covidstats DESTINATION bin)
