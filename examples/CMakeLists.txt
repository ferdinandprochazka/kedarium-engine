# Executable
add_executable(
  example
  Main.cpp
)

# Include Directories
target_include_directories(example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Libraries
target_link_libraries(example PRIVATE Kedarium GL GLEW::GLEW glfw)
