#include "GrepWorker.h"

namespace workflow {

    GrepWorker::GrepWorker(WorkingCreatingContext* creatingContext) {
        this->findWord = creatingContext->arg1;
        this->data = creatingContext->data;
        delete creatingContext;
    }

    void GrepWorker::setStringWithWord(const std::vector<std::string>& vectorOfString) {
        *this->data = "";
        for (auto str : vectorOfString) {
            if (str.find(this->findWord) != std::string::npos) {
                *this->data += (str + this->SEPARATOR);
            }
        }
    }

    void GrepWorker::run() {
        std::vector<std::string> vectorOfString = workflow::splitString<std::string>(*this->data, this->SEPARATOR);
        this->setStringWithWord(vectorOfString);
    }

}
