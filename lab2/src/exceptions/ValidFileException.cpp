#include "ValidFileException.h"

namespace workflow {

	ValidFileException::ValidFileException(std::auto_ptr<WorkflowExceptionContext*> context) {
		this->context = context;
	}

	ValidFileException::~ValidFileException() {}

	void ValidFileException::showProblem() {
		std::cerr << (*this->context)->errorString << std::endl;
	}

}
