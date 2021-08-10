#ifndef MAPLOADER_H
#define MAPLOADER_H
#include "gameconstants.h"
#include "openfileexception.h"
#include <iostream>
#include <string>
#include <fstream>

#pragma once

namespace game {

    class MapLoader {
    private:
        std::string pathToFile;
        int* map;

    public:
        MapLoader(std::string pathToFile, int* map);
        void loadMap();

    private:
        int countOfToken;
        void parseString(std::string str);
    };

}
#endif // MAPLOADER_H
