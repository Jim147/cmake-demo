cmake_minimum_required(VERSION 3.17)

project(Demo2)

#to include all directories
include_directories(. ./math)

#to include all source code in these directories
aux_source_directory(. CF)
aux_source_directory(./math MATH)

add_executable(Demo22 ${CF} ${MATH})



