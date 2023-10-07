#ifndef KDR_CORE_HPP
#define KDR_CORE_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

namespace kdr
{
  namespace Core
  {
    /**
     * Prints information about the engine.
     */
    void printEngineInfo();
    /**
     * Prints version information about OpenGL, GLFW, and GLEW.
     */
    void printVersionInfo();
  }
}

#endif // KDR_CORE_HPP
