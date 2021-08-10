#include "ReadWorker.h"

namespace workflow {

	ReadWorker::ReadWorker(WorkingCreatingContext* creatingContext) {
		this->inputDate = creatingContext->data;
		this->pathToFile = creatingContext->arg1;
		delete creatingContext;
	}

	void ReadWorker::open() {
		this->inputFileStream.open(this->pathToFile);
		if (!this->inputFileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Input file opening error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
	}

	void ReadWorker::read() {
		std::ostringstream oss;
		oss << this->inputFileStream.rdbuf();
		*this->inputDate = oss.str();
	}

	void ReadWorker::close() {
		this->inputFileStream.close();
	}

	void ReadWorker::run() {
		this->open();
		this->read();
		this->close();
	}

}