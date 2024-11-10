#!/bin/sh

set -e  # Exit immediately on error

echo "Root directory: " $PWD
PROJECT_NAME="PracticeCPP"
BUILD_FOLDER="./build"

# CMake to generate build instruction
cmake -S . -B $BUILD_FOLDER

# Clean Only
# cmake --build $BUILD_FOLDER --target clean

# Clean and Build
cmake --build $BUILD_FOLDER --target $PROJECT_NAME --clean-first

echo "The program starts .."

# Run the executable
$BUILD_FOLDER/$PROJECT_NAME

echo "The program completed!"


