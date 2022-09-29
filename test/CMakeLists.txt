include_directories(${PROJECT_SOURCE_DIR}/include)

find_package(GTest REQUIRED)

macro(make_test fname)
    add_executable(${fname} ${fname}.cpp)
    target_link_libraries(${fname} HPart)
    target_compile_definitions(${fname} PRIVATE -DSOURCE_DIR="${PROJECT_SOURCE_DIR}")
endmacro()

make_test(test_io)
