#pragma once

#include "WorkflowExceptionInterface.h"
#include "WorkflowExceptionContext.h"

namespace workflow {

	class ValidFileException : public WorkflowExceptionInterface {
	private:
		std::auto_ptr<WorkflowExceptionContext*> context;
	public:
		ValidFileException(std::auto_ptr<WorkflowExceptionContext*> context);
		~ValidFileException();
		void showProblem() override;
	};

}
