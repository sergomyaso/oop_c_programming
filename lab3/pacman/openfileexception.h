#ifndef OPENFILEEXCEPTION_H
#define OPENFILEEXCEPTION_H


#pragma once
#include <iostream>
#include <string>

namespace game {

    class OpenFileException {
    private:
        std::string problem;

    public:
        OpenFileException(std::string problem);
        void showProblem();
    };

}

#endif // OPENFILEEXCEPTION_H
