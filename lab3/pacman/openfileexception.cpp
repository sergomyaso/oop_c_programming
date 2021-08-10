#include "openfileexception.h"

namespace game {

    OpenFileException::OpenFileException(std::string problem) {
        this->problem = problem;
    }

    void OpenFileException::showProblem() {
        std::cerr << problem;
    }

}
