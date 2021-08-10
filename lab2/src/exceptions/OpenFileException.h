#pragma once

#include "WorkflowExceptionInterface.h"
#include "WorkflowExceptionContext.h"

namespace workflow {

	class OpenFileException : public WorkflowExceptionInterface {

	private:
		std::auto_ptr<WorkflowExceptionContext*> context;

	public:
		OpenFileException(std::auto_ptr<WorkflowExceptionContext*> context);
		~OpenFileException();
		void showProblem() override;
	};

}
