cmake_minimum_required(VERSION 3.15)
project(translators
        VERSION 0.1.0
        DESCRIPTION "Translator library for c++"
        LANGUAGES CXX
        )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) # Introduce Conan-generated targets

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
option(BUILD_LOCALLY "create a local executable bin" ON)


add_definitions(-D_GLIBCXX_USE_CXX11_ABI=0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(translators src/translators.cpp src/base.cpp src/google.cpp src/mymemory.cpp)
target_link_libraries(translators  CONAN_PKG::cpr)
target_compile_features(translators PUBLIC cxx_std_17)

if (BUILD_LOCALLY)
        message(STATUS "building locally: output-> example")
        add_executable(example examples/main.cpp)
        target_link_libraries(example translators)
       
else()

        message(STATUS "building library")
        set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "src/translators.hpp")
        install(TARGETS ${PROJECT_NAME} DESTINATION "."
                PUBLIC_HEADER DESTINATION include
                RUNTIME DESTINATION bin
                ARCHIVE DESTINATION lib
                LIBRARY DESTINATION lib
                )
endif()