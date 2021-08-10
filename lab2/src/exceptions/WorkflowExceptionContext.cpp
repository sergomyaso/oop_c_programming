#include "WorkflowExceptionContext.h"

namespace workflow {

	WorkflowExceptionContext::WorkflowExceptionContext(std::string errorString) {
		this->errorString = errorString;
	}

	WorkflowExceptionContext::WorkflowExceptionContext() {
		this->errorString = this->DEFOULT_ERROR_STRING;
	}

}
