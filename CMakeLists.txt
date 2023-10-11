cmake_minimum_required(VERSION 3.2)

set(PATCH_VERSION "0" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(helloworld VERSION ${PROJECT_VESRION})

# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

# Library
configure_file(version.h.in version.h)
add_library(helloworld lib.cpp)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)
target_compile_options(helloworld
    PRIVATE -Wall -Wextra -pedantic -Werror
)

# application
add_executable(helloworld_cli main.cpp)
target_link_libraries(helloworld_cli PRIVATE
    helloworld
)
target_compile_options(helloworld_cli 
    PRIVATE -Wall -Wextra -pedantic -Werror
)

set_target_properties(helloworld_cli helloworld PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

# test





install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

# add_test(test_version test_version)
