#include "DumpWorker.h"

namespace workflow {

	DumpWorker::DumpWorker(WorkingCreatingContext* creatingContext) {
		this->data = creatingContext->data;
		this->pathToFile = creatingContext->arg1;
		delete creatingContext;
	}

	void DumpWorker::open() {
		this->outFileStream.open(this->pathToFile);
		if (!this->outFileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Output file opening error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
	}

	void DumpWorker::write() {
		this->outFileStream << (*this->data);
	}

	void DumpWorker::close() {
		this->outFileStream.close();
	}

	void DumpWorker::run() {
		this->open();
		this->write();
		this->close();
	}

}
