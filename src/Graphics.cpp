#include "Kedarium/Graphics.hpp"
#include "Kedarium/File.hpp"

kdr::Graphics::Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
  std::string vertexShaderSource = kdr::File::getContents(vertexPath);
  std::string fragmentShaderSource = kdr::File::getContents(fragmentPath);

  const char *vertexCStringSource = vertexShaderSource.c_str();
  const char *fragmentCStringSource = fragmentShaderSource.c_str();

  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

  glShaderSource(vertexShader, 1, &vertexCStringSource, NULL);
  glShaderSource(fragmentShader, 1, &fragmentCStringSource, NULL);

  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);

  char infoLog[512];
  int success;

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the vertex shader (" << vertexPath << ")!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cerr << "Failed to compile the fragment shader (" << fragmentPath << ")!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  this->ID = glCreateProgram();

  glAttachShader(this->ID, vertexShader);
  glAttachShader(this->ID, fragmentShader);
  glLinkProgram(this->ID);

  glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
    std::cerr << "Failed to link the shader program!" << std::endl;
    std::cerr << "Error: " << infoLog << std::endl;
  }

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

const GLuint kdr::Graphics::Shader::getID() const
{
  return this->ID;
}

void kdr::Graphics::Shader::Use()
{
  glUseProgram(this->ID);
}

void kdr::Graphics::Shader::Delete()
{
  glDeleteProgram(this->ID);
}

kdr::Graphics::VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
  glGenBuffers(1, &this->ID);
  glBindBuffer(GL_ARRAY_BUFFER, this->ID);
  glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

const GLuint kdr::Graphics::VBO::getID() const
{
  return this->ID;
}

void kdr::Graphics::VBO::Bind()
{
  glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void kdr::Graphics::VBO::Unbind()
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void kdr::Graphics::VBO::Delete()
{
  glDeleteBuffers(1, &this->ID);
}
