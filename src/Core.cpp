#include "Kedarium/Core.hpp"

const char* ENGINE_NAME    = "Kedarium Engine";
const char* ENGINE_VERSION = "0.1";
const char* ENGINE_AUTHOR  = "Ferdinand Procházka";
const char* ENGINE_LICENSE = "GNU GPLv3";

void kdr::Core::printEngineInfo()
{
  std::cout << ENGINE_NAME << " " << ENGINE_VERSION << '\n';
  std::cout << "Created by " << ENGINE_AUTHOR << '\n';
  std::cout << "Licensed under " << ENGINE_LICENSE << '\n';
}

void kdr::Core::printVersionInfo()
{
  std::cout << '\n';
  std::cout << "OpenGL: " << glGetString(GL_VERSION) << '\n'; 
  std::cout << "GLFW:   " << glfwGetVersionString() << '\n'; 
  std::cout << "GLEW:   " << glewGetString(GLEW_VERSION) << '\n'; 
}
