
# Library
configure_file(version.h.in version.h)
add_library(helloworld lib.cpp)
target_include_directories(helloworld PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(helloworld PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message("target_include_directories INTERFACE: ${CMAKE_CURRENT_SOURCE_DIR}")

