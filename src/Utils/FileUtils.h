//
// Created by VrikkaDev on 30/03/2023.
//

#ifndef OPENGLRENDERING_FILEUTILS_H
#define OPENGLRENDERING_FILEUTILS_H

#include "pch.h"

class FileUtils {
public:
    // Read the contents of a file at a given file path and return it as a string.
    static std::string* ReadFileString(const char* filePath);

    // Read the contents of a file at a given relative file path and return it as a string.
    // The file path is relative to the parent directory of the current working directory.
    static std::string* ReadRelativeFileString(const char* filePath);
};


#endif //OPENGLRENDERING_FILEUTILS_H
