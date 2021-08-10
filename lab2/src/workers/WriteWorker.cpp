#include "WriteWorker.h"

namespace workflow{

	WriteWorker::WriteWorker(WorkingCreatingContext* creatingContext) {
		this->pathToFile = creatingContext->arg1;
		this->data = creatingContext->data;
		delete creatingContext;
	}

	void WriteWorker::open() {
		this->outFileStream.open(this->pathToFile);
		if (!this->outFileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Output file opening error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
	}

	void WriteWorker::write() {
		this->outFileStream << (*this->data);
	}

	void WriteWorker::close() {
		this->outFileStream.close();
	}

	void WriteWorker::run() {
		this->open();
		this->write();
		this->close();
	}

}
