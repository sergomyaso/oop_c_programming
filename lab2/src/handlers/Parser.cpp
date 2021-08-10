#include "Parser.h"

namespace workflow {

    Parser::Parser(std::string* data) {
        this->data = data;
    }

    WorkingCreatingContext* Parser::parse(std::string line) {
        auto splitedLine = workflow::splitString<std::string>(line, this->SEPARETOR);
        WorkflowValidator validator;

        if (!validator.isValidString(splitedLine)) {
            auto context = new WorkflowExceptionContext("Invalid worker arguments");
            throw ValidFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
        }
        if (splitedLine.size() == this->SIZE_WITHOUT_PARAMS)
            return new WorkingCreatingContext(this->data, this->DEFOULT_ARG, this->DEFOULT_ARG, splitedLine[this->INDEX_WORKER_NAME]);

        if (splitedLine.size() == this->SIZE_ONE_PARAM)
            return new WorkingCreatingContext(this->data, splitedLine[this->INDEX_FIRST_ARG], this->DEFOULT_ARG, splitedLine[this->INDEX_WORKER_NAME]);

        return new WorkingCreatingContext(this->data, splitedLine[this->INDEX_FIRST_ARG], splitedLine[this->INDEX_SECOND_ARG], splitedLine[this->INDEX_WORKER_NAME]);
    }

}
