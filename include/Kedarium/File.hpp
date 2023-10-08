#ifndef KDR_FILE_HPP
#define KDR_FILE_HPP

#include <string>
#include <fstream>
#include <iostream>

namespace kdr
{
  namespace File
  {
    /**
     * Reads the contents of a file into a string.
     *
     * @param path The path to the file to be read.
     * @return A string containing the contents of the file. If an error occurs,
     *         an empty string is returned.
     */
    std::string getContents(std::string path);
  }
}

#endif // KDR_FILE_HPP
