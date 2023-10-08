#ifndef KDR_WINDOW_HPP
#define KDR_WINDOW_HPP

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

#include "Colors.hpp"

namespace kdr
{
  /**
   * Struct to store window properties.
   */
  struct WindowProps
  {
    unsigned int width;
    unsigned int height;
    std::string title;

    /**
     * Constructor for initializing window properties.
     *
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The title of the window.
     */
    WindowProps(
      const unsigned int width,
      const unsigned int height,
      const std::string title
    ) : title(title), width(width), height(height)
    {};
  };

  /**
   * Represents an application window for rendering.
   */
  class Window
  {
    public:
      /**
       * Constructs a Window object with the specified properties.
       *
       * @param windowProps The properties for configuring the window.
       */
      Window(const WindowProps& windowProps);

      /**
       * Gets a pointer to the GLFW window associated with the object.
       *
       * @return A pointer to the GLFW window.
       */
      GLFWwindow* getWindow() const;
      /**
       * Gets the width of the window.
       * 
       * @return The width of the window.
       */
      const unsigned int getWidth() const;
      /**
       * Gets the height of the window.
       * 
       * @return The height of the window.
       */
      const unsigned int getHeight() const;

      /**
       * Sets the clear color for the window.
       *
       * @param clearColor The RGBA color to set as the clear color.
       */
      void setClearColor(const kdr::Colors::RGBA& clearColor);

      /**
       * Main loop for the window.
       */
      void loop();
      /**
       * Closes the window.
       */
      void close();

    protected:
      /**
       * Update function (to be overridden by derived classes).
       */
      virtual void update() = 0;
      /**
       * Render function (to be overridden by derived classes).
       */
      virtual void render() = 0;

    private:
      GLFWwindow* window;
      unsigned int width{800};
      unsigned int height{600};
      std::string title{"Kedarium Engine"};

      kdr::Colors::RGBA clearColor = kdr::Colors::RGBA(
        0.f,
        0.f,
        0.f,
        1.f
      );

      /**
       * Base function for updating the window.
       */
      void _update();
      /**
       * Base function for rendering the window.
       */
      void _render();
  };
}

#endif // KDR_WINDOW_HPP
