cmake_minimum_required(VERSION 3.30)

# Common information/variables, set depends on your project
set(PROJECT_NAME "PracticeCPP")

project(${PROJECT_NAME}
        LANGUAGES CXX
        VERSION 0.0.1
        DESCRIPTION "This suppose to use for learning C++, which follows standart C++ project sturcture. Also use CMake as to work cross platfrom")

# Manually specify source files
# add_executable(PracticeCPP src/main.cpp)

#GLOB to auto scan, select all cpp file. Then store the result as list named SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
#Specify target and source file to make it
add_executable(${PROJECT_NAME} src/main.cpp ${SOURCE_FILES})

# Specify c++ standart version
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
# Specify where the header files are
target_include_directories( ${PROJECT_NAME} PRIVATE 
                            ${CMAKE_CURRENT_SOURCE_DIR}/include 
                            ${CMAKE_CURRENT_SOURCE_DIR}/src)