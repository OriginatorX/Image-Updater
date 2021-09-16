@echo off
echo "Building for windows"

IF exist build ( 
    echo DIR build exists
    rmdir /S build && echo DIR build deleted
)
mkdir build && echo DIR build created
echo using generator %1

cd build
cmake -G %1 .. 
cmake --build .
