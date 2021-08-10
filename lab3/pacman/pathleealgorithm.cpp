#include "pathleealgorithm.h"

namespace game {

    PathLeeAlgorithm::PathLeeAlgorithm(int* realMap){
        this->realMap = realMap;
    }

    void PathLeeAlgorithm::generateMapMatrix(int* mapMatrix) {
        for (int i = 0; i < WIDTH_MAP * HEIGHT_MAP; i++) {
            mapMatrix[i] = -realMap[i];
        }
    }

    bool PathLeeAlgorithm::leeALgorithmFindShortestPath(QPair<int, int> beginPoint, QPair<int, int> endPoint) {
        beginPoint.first = (WIDTH_OF_BOUNDING__RECT_SCENE + X_OF_BOUNDING__RECT_SCENE + beginPoint.first) / LabirintPart::WIDTH_OF_BOUNDING_RECT;
        beginPoint.second = (HEIGHT_OF_BOUNDING__RECT_SCENE + Y_OF_BOUNDING__RECT_SCENE + beginPoint.second) / LabirintPart::HEIGHT_OF_BOUNDING_RECT;

        endPoint.first = (WIDTH_OF_BOUNDING__RECT_SCENE + X_OF_BOUNDING__RECT_SCENE + endPoint.first) / LabirintPart::WIDTH_OF_BOUNDING_RECT;
        endPoint.second = (HEIGHT_OF_BOUNDING__RECT_SCENE + Y_OF_BOUNDING__RECT_SCENE + endPoint.second) / LabirintPart::HEIGHT_OF_BOUNDING_RECT;
        int len = 0;
        int mapMatrix[HEIGHT_MAP * WIDTH_MAP];
        generateMapMatrix(mapMatrix);
        int offsetsX[COUNT_OF_AXIS] = { 1, 0, -1, 0 };   // offsets neighbors of point
        int offsetsY[COUNT_OF_AXIS] = { 0, 1, 0, -1 };
        int d, x, y, k;
        bool stop;
        if (mapMatrix[beginPoint.second * WIDTH_MAP + beginPoint.first] == WALL_OF_LABIRINT || mapMatrix[endPoint.second * WIDTH_MAP + endPoint.first] == WALL_OF_LABIRINT)
            return false;
        /* Make wave */
        d = 0;
        mapMatrix[beginPoint.second * WIDTH_MAP + beginPoint.first] = 0;            // Begin = 0, tagged
        do {
            stop = true;               // We thin, that all free neghbors is tagged
            for (y = 0; y < HEIGHT_MAP; ++y)
                for (x = 0; x < WIDTH_MAP; ++x)
                    if (mapMatrix[y * WIDTH_MAP + x] == d)                         // Point (x, y) tagged by d
                    {
                        for (k = 0; k < COUNT_OF_AXIS; ++k)                    // We go around all the neighbors
                        {
                            int iy = y + offsetsY[k], ix = x + offsetsX[k];
                            if (iy >= 0 && iy < HEIGHT_MAP && ix >= 0 && ix < WIDTH_MAP &&
                                mapMatrix[iy * WIDTH_MAP + ix] == BLANK_OF_LABIRINT)
                            {
                                stop = false;              // Find not tagged
                                mapMatrix[iy * WIDTH_MAP + ix] = d + 1;      // Make wave
                            }
                        }
                    }
            d++;
        } while (!stop && mapMatrix[endPoint.second * WIDTH_MAP + endPoint.first] == BLANK_OF_LABIRINT);

        if (mapMatrix[endPoint.second * WIDTH_MAP + endPoint.first] == BLANK_OF_LABIRINT)
            return false;  // Path not found

        // Get find path
        len = mapMatrix[endPoint.second * WIDTH_MAP + endPoint.first];            // длина кратчайшего пути из (ax, ay) в (bx, by)
        x = endPoint.first;
        y = endPoint.second;
        d = len;
        if (pathToTarget.size() > 0)
            pathToTarget.clear();
        while (d > 0)
        {
            pathToTarget.push_front(QPair<int, int>(LabirintPart::WIDTH_OF_BOUNDING_RECT * x - (WIDTH_OF_BOUNDING__RECT_SCENE + X_OF_BOUNDING__RECT_SCENE), LabirintPart::HEIGHT_OF_BOUNDING_RECT * y - (WIDTH_OF_BOUNDING__RECT_SCENE + Y_OF_BOUNDING__RECT_SCENE)));
            d--;
            for (k = 0; k < COUNT_OF_AXIS; ++k)
            {
                int iy = y + offsetsY[k], ix = x + offsetsX[k];
                if (iy >= 0 && iy < HEIGHT_MAP && ix >= 0 && ix < WIDTH_MAP &&
                    mapMatrix[iy * WIDTH_MAP + ix] == d)
                {
                    x = x + offsetsX[k];
                    y = y + offsetsY[k];           // Get next point
                    break;
                }
            }
        }
        pathToTarget.push_front(QPair<int, int>(beginPoint.first * LabirintPart::WIDTH_OF_BOUNDING_RECT - (WIDTH_OF_BOUNDING__RECT_SCENE + X_OF_BOUNDING__RECT_SCENE), LabirintPart::HEIGHT_OF_BOUNDING_RECT * beginPoint.second - (WIDTH_OF_BOUNDING__RECT_SCENE + Y_OF_BOUNDING__RECT_SCENE)));
        return true;
    }

    QVector<QPair<int, int>> PathLeeAlgorithm::getPath(QPair<int, int> beginPoint, QPair<int, int> endPoint) {
        leeALgorithmFindShortestPath(beginPoint, endPoint);
        return pathToTarget;
    }
}
