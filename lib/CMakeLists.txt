add_library(casesrepo src/CasesRepository/RKICasesRepository.cpp
                      src/ResultStream/StdoutResultStream.cpp
                      src/ResultStream/FileResultStream.cpp)

find_package(cpprestsdk CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

target_include_directories(casesrepo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(casesrepo PUBLIC cpprestsdk::cpprest nlohmann_json::nlohmann_json)

if(MSVC)
    target_compile_options(casesrepo PRIVATE /W4 /WX)
else()
    target_compile_options(casesrepo PRIVATE -Wall -Wextra -pedantic -Werror)
endif()
