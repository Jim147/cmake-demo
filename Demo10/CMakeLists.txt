cmake_minimum_required (VERSION 2.8)

project (mat)

#add_subdirectory(../lib1)

aux_source_directory(. SRC_LIST)

#include_directories (${PROJECT_SOURCE_DIR}/lib1/include)

link_directories(/usr/local/lib)

add_executable(mat ${SRC_LIST})

target_link_libraries(mat m gsl)