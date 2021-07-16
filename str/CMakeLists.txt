cmake_minimum_required(VERSION 3.5)

project(03.hello_world)
message("library")
set ( HEADERS
    move_me_out.h
    example.h

)
set ( SOURCER
     move_me_out.cpp
    example.cpp
)
add_library(lib STATIC ${HEADERS} ${SOURCER})

set_target_properties(lib
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)


target_include_directories (lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

