#pragma once

#include <iostream>
#include <string>

namespace workflow {

	class WorkflowExceptionContext {
	private:
		const std::string DEFOULT_ERROR_STRING = "WorkflowError";
	public:
		std::string errorString;
	public:
		WorkflowExceptionContext(std::string errorString);
		WorkflowExceptionContext();

	};

}
