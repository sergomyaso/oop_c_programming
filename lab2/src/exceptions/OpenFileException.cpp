#include "OpenFileException.h"

namespace workflow {

	OpenFileException::OpenFileException(std::auto_ptr<WorkflowExceptionContext*> context) {
		this->context = context;
	}

	OpenFileException::~OpenFileException() {
		//delete *this->context;
	}

	void OpenFileException::showProblem() {
		std::cerr << (*this->context)->errorString << std::endl;
	}

}
