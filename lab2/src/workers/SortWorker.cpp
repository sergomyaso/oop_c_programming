#include "SortWorker.h"

namespace workflow {

    SortWorker::SortWorker(WorkingCreatingContext* creatingContext) {
        this->data = creatingContext->data;
        delete creatingContext;
    }

    std::vector <std::string> SortWorker::splitString(char separator) {
        std::vector<std::string> splitedString;
        std::stringstream stringStream;
        stringStream.str(*this->data);
        std::string item;

        while (std::getline(stringStream, item, separator)) {
            splitedString.push_back(item);
        }
        return splitedString;
    }

    void SortWorker::sortLexic(std::vector<std::string>& strings) {
        std::sort(strings.begin(), strings.end());
    }

    void SortWorker::setStringFromVector(const std::vector<std::string>& vectorOfString) {
        *this->data = "";
        for (auto str : vectorOfString) {
            *this->data += (str + this->SEPARATOR);
        }
    }

    void SortWorker::run() {
        std::vector <std::string> splitedString = this->splitString(this->SEPARATOR);
        this->sortLexic(splitedString);
        this->setStringFromVector(splitedString);
    }

}
