# Version
cmake_minimum_required(VERSION 3.5)

# Constants
set(PROJECT_NAME "kedarium")
set(OpenGL_GL_PREFERENCE LEGACY)

# Project Name
project(${PROJECT_NAME})

# Packages
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

# CXX Standard
set(CXX_STANDARD_REQUIRED 11)

# Include Directory
include_directories(include)

# Subdirectories
add_subdirectory(src)
add_subdirectory(examples)

# Copy Resource Files
file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})
