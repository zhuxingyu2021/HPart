include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

macro(make_test fname)
    add_executable(${fname} ${fname}.cpp)
    target_link_libraries(${fname} HPart ${GTEST_LIBRARIES} pthread)
    target_compile_definitions(${fname} PRIVATE -DSOURCE_DIR="${PROJECT_SOURCE_DIR}")
endmacro()

make_test(test_io)
