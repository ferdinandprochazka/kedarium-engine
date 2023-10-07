#ifndef KDR_COLORS_HPP
#define KDR_COLORS_HPP

namespace kdr
{
  namespace Colors
  {
    /**
     * Represents a color in RGB (Red, Green, Blue) format.
     */
    struct RGB
    {
      float red;
      float green;
      float blue;

      /**
       * Constructor for creating an RGB color.
       *
       * @param red The red component of the color (0.0 - 1.0).
       * @param green The green component of the color (0.0 - 1.0).
       * @param blue The blue component of the color (0.0 - 1.0).
       */
      RGB(
        const float red,
        const float green,
        const float blue
      ) : red(red), green(green), blue(blue)
      {};
    };

    /**
     * Represents a color in RGBA (Red, Green, Blue, Alpha) format.
     */
    struct RGBA
    {
      float red;
      float green;
      float blue;
      float alpha;

      /**
       * Constructor for creating an RGBA color.
       *
       * @param red The red component of the color (0.0 - 1.0).
       * @param green The green component of the color (0.0 - 1.0).
       * @param blue The blue component of the color (0.0 - 1.0).
       * @param alpha The alpha (transparency) component of the color (0.0 - 1.0).
       */
      RGBA(
        const float red,
        const float green,
        const float blue,
        const float alpha
      ) : red(red), green(green), blue(blue), alpha(alpha)
      {};
    };
  }
}

#endif // KDR_COLORS_HPP
