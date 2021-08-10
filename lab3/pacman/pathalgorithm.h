#ifndef PATHALGORITHM_H
#define PATHALGORITHM_H

#endif // PATHALGORITHM_H
#pragma once

#include <iostream>
#include <QVector>
#include <QPair>
namespace game {

    class PathAlgorithm {
    public:
        virtual QVector<QPair<int, int>> getPath(QPair<int, int> beginPoint, QPair<int, int> endPoint) = 0;
    };

}
