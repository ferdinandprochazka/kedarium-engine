#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#include "Kedarium/Core.hpp"
#include "Kedarium/Window.hpp"
#include "Kedarium/Colors.hpp"
#include "Kedarium/Graphics.hpp"

// Constants
const unsigned int WINDOW_WIDTH  = 800;
const unsigned int WINDOW_HEIGHT = 600;
const std::string  WINDOW_TITLE  = "Kedarium Engine";

// Vertices and Indices
GLfloat vertices[] = {
  -0.5f,  -0.5f, 0.f, 1.f, 0.f, 0.f,
   0.0f,  -0.5f, 0.f, 0.f, 1.f, 0.f,
   0.5f,  -0.5f, 0.f, 0.f, 0.f, 1.f,
  -0.25f,  0.0f, 0.f, 1.f, 1.f, 0.f,
   0.25f,  0.0f, 0.f, 1.f, 0.f, 1.f,
   0.f,    0.5f, 0.f, 0.f, 1.f, 1.f,
};
GLuint indices[] = {
  0, 1, 3,
  1, 2, 4,
  3, 4, 5,
};

class MyWindow : public kdr::Window
{
  public:
    MyWindow(const kdr::WindowProps& windowProps) : kdr::Window(windowProps)
    {
      // Shader
      this->defaultShader = new kdr::Graphics::Shader(
        "resources/Shaders/default.vert",
        "resources/Shaders/default.frag"
      );
      
      // VAO, VBO, and EBO
      this->VAO1 = new kdr::Graphics::VAO();
      this->VBO1 = new kdr::Graphics::VBO(vertices, sizeof(vertices));
      this->EBO1 = new kdr::Graphics::EBO(indices, sizeof(indices));

      this->VAO1->Bind();
      this->EBO1->Bind();
      this->VBO1->Bind();

      this->VAO1->LinkAttrib(*this->VBO1, 0, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)0);
      this->VAO1->LinkAttrib(*this->VBO1, 1, 3, GL_FLOAT, 6 * sizeof(GLfloat), (void*)(3 * sizeof(GLfloat)));

      this->VAO1->Unbind();
      this->VBO1->Unbind();
      this->EBO1->Unbind();
    }

    ~MyWindow()
    {
      this->defaultShader->Delete();
      this->VAO1->Delete();
      this->VBO1->Delete();
      this->EBO1->Delete();

      delete this->defaultShader;
      delete this->VAO1;
      delete this->VBO1;
      delete this->EBO1;
    }

    void update(){}

    void render()
    {
      this->defaultShader->Use();
      this->VAO1->Bind();
      glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(GLuint), GL_UNSIGNED_INT, NULL);
    }

  private:
    kdr::Graphics::Shader* defaultShader;

    kdr::Graphics::VAO* VAO1;
    kdr::Graphics::VBO* VBO1;
    kdr::Graphics::EBO* EBO1;
};

int main()
{
  // Window
  kdr::WindowProps windowProps = kdr::WindowProps(
    WINDOW_WIDTH,
    WINDOW_HEIGHT,
    WINDOW_TITLE
  );
  MyWindow myWindow(windowProps);

  // Clear Color
  kdr::Colors::RGBA clearColor = kdr::Colors::RGBA(
    0.0,
    0.3,
    0.3,
    1.f
  );
  myWindow.setClearColor(clearColor);

  // Info Logs
  kdr::Core::printEngineInfo();
  kdr::Core::printVersionInfo();

  // Main Loop
  myWindow.loop();
  myWindow.close();

  return 0;
}
