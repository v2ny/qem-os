#pragma once

#include <cstdint>

class Directory
{
    public:
        const char* read(const char* directoryPath, unsigned int maxEntries = 24);
};