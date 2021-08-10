#include "WorkflowApp.h"

namespace workflow {

	WorkflowApp::WorkflowApp(const std::string pathToFile, const bool testFlag) {
		this->pathToFile = pathToFile;
		this->testFlag = testFlag;
	}

	void WorkflowApp::executeWorkers() {

		std::map<std::string, std::function<workflow::WorkerIntreface* (workflow::WorkingCreatingContext* context)>> creators;
		creators["readfile"] = [](workflow::WorkingCreatingContext* context) { return new workflow::ReadWorker(context); };
		creators["writefile"] = [](workflow::WorkingCreatingContext* context) { return new workflow::WriteWorker(context); };
		creators["grep"] = [](workflow::WorkingCreatingContext* context) { return new workflow::GrepWorker(context); };
		creators["sort"] = [](workflow::WorkingCreatingContext* context) { return new workflow::SortWorker(context); };
		creators["replace"] = [](workflow::WorkingCreatingContext* context) { return new workflow::ReplaceWorker(context); };
		creators["dump"] = [](workflow::WorkingCreatingContext* context) { return new workflow::DumpWorker(context); };

		WorkflowReader reader(this->pathToFile);
		auto queueWorkers = reader.getWorkerQueue();
		Parser pars(&this->data);

		while (queueWorkers.size() != 0) {
			WorkingCreatingContext* context = pars.parse(queueWorkers.front());
			queueWorkers.pop();
			auto creator = creators[context->workerName];
			auto worker = creator(context);
			worker->run();
			delete worker;
		}
	}

	void WorkflowApp::runApp() {
		if (!this->testFlag) {
			try {
				this->executeWorkers();
			}
			catch (workflow::WorkflowExceptionInterface& exep) {
				exep.showProblem();
				return;
			}
		}

		try {
			this->executeWorkers();
		}
		catch(workflow::OpenFileException& exep) {
			auto context = new WorkflowExceptionContext();
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		catch (workflow::ValidFileException& exep) {
			auto context = new WorkflowExceptionContext();
			throw ValidFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
	}

}
