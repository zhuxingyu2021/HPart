include_directories(${PROJECT_SOURCE_DIR}/include)

set(SRCFILE
        io.cpp)

add_library(HPart SHARED ${SRCFILE})
