cmake_minimum_required(VERSION 3.5)

project(libraries)
message("main_hello")
add_executable(hello_world 
    hello_world.cpp 
)

set_target_properties(hello_world PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)
include_directories("../str")

target_link_libraries(hello_world lib)
