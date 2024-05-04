#!/bin/bash

# Check if a filename was provided as an argument `./run.sh your_file.cpp`
if [ $# -eq 0 ]; then
    echo "No filename provided."
    exit 1
fi

# Get the filename from the first argument `your_file.cpp`
cpp_file=$1

# Check if the file exists
if [ ! -f "$cpp_file" ]; then
    echo "File does not exist: $cpp_file"
    exit 1
fi

# Get the filename without the extension `your_file`
file_name="${cpp_file%.*}"

# Compile the C++ code
g++ "$cpp_file" -o "$file_name.o"

# Run the program
./"$file_name.o"