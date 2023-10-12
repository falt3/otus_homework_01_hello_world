
add_executable(test_version test.cpp)

target_link_libraries(test_version PRIVATE
    helloworld
)

find_package(GTest)
target_include_directories(test_version PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_version PRIVATE ${GTEST_BOTH_LIBRARIES})

add_test(
    NAME test1 
    COMMAND test_version
)