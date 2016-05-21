cmake_minimum_required(VERSION 2.8)

## Use the variable PROJECT_NAME for changing the target name
set( PROJECT_NAME "clame-core" )

## Set our project name
project(${PROJECT_NAME})

## Use all the *.cpp files we found under this folder for the project
FILE(GLOB SRCS "*.cpp" "*.c")

## Linking against specific libraries
##target_link_libraries() 	NEED FURTHER TESTING

## Define the executable
add_executable(${PROJECT_NAME} ${SRCS})
