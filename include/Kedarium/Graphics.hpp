#ifndef KDR_GRAPHICS_HPP
#define KDR_GRAPHICS_HPP

#include <GL/glew.h>
#include <string>

namespace kdr
{
  namespace Graphics
  {
    /**
   * Represents an OpenGL shader program.
   */
    class Shader
    {
      public:
        /**
         * Constructor for the Shader class.
         *
         * @param vertexPath The path to the vertex shader source file.
         * @param fragmentPath The path to the fragment shader source file.
         */
        Shader(std::string vertexPath, std::string fragmentPath);

        /**
         * Gets the ID of the shader program.
         *
         * @return The shader program ID.
         */
        const GLuint getID() const;

        /**
         * Activates the shader program for rendering.
         */
        void Use();
        /**
         * Deletes the shader program.
         */
        void Delete();

      private:
        GLuint ID;
    };

    /**
   * Represents a Vertex Buffer Object (VBO) used in OpenGL rendering.
   */
    class VBO
    {
      public:
        /**
         * Constructor for creating a VBO.
         * 
         * @param vertices A pointer to an array of GLfloat containing vertex data.
         * @param size The size in bytes of the vertex data.
         */
        VBO(GLfloat* vertices, GLsizeiptr size);

        /**
         * Gets the ID of the VBO.
         * 
         * @return The ID of the VBO.
         */
        const GLuint getID() const;

        /**
         * Binds the VBO for use.
         */
        void Bind();
        /**
         * Unbinds the currently bound VBO.
         */
        void Unbind();
        /**
         * Deletes the VBO, releasing its resources.
         */
        void Delete();

      private:
        GLuint ID;
    };
  }
}

#endif // KDR_GRAPHICS_HPP
