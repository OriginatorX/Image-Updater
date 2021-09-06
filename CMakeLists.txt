cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

project(ImageChanger)

set(SOURCES 
    main.cpp
    ./src/UserContent.cpp

    ./src/include/Randoms.h
    ./src/include/UserContent.h
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)
