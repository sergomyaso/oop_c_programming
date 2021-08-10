#include "maploader.h"

namespace game {

    MapLoader::MapLoader(std::string pathToFile, int* map) {
        this->pathToFile = pathToFile;
        this->map = map;
    }

    void MapLoader::parseString(std::string str) {
        for (auto token : str) {
            if (token != '\n') {
                map[countOfToken] = (int)token - 48;
                countOfToken++;
            }
        }
    }

    void MapLoader::loadMap() {
        std::fstream fin(this->pathToFile);
        if (!fin.is_open()) {
            throw OpenFileException("Bad path");
        }
        countOfToken = 0;
        while (!fin.eof()) {
            std::string line;
            getline(fin, line);
            this->parseString(line);
        }
        fin.close();
    }

}
