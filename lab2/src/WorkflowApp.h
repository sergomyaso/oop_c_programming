#pragma once

#include <iostream>
#include <map>
#include <string>
#include <functional>

#include "workers/WriteWorker.h"
#include "workers/ReadWorker.h"
#include "workers/GrepWorker.h"
#include "workers/DumpWorker.h"
#include "workers/ReplaceWorker.h"
#include "workers/WorkingCreatingContext.h"
#include "workers/SortWorker.h"
#include "workers/WorkerInterface.h"
#include "handlers/Parser.h"
#include "handlers/WorkflowReader.h"

namespace workflow {

	class WorkflowApp {
	private:
		bool testFlag;
		std::string data;
		std::string pathToFile;

	private:
		void executeWorkers();

	public:
		WorkflowApp(const std::string pathToFile, const bool testFlag);
		void runApp();
	};

}
