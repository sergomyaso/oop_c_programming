#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "WorkerInterface.h"
#include "WorkingCreatingContext.h"
#include "WorkflowFunctions.h"

namespace workflow {
	class GrepWorker : public WorkerIntreface {
	private:
		std::string findWord;
		std::string* data;
		static const char SEPARATOR = '\n';

	private:
		void setStringWithWord(const std::vector<std::string>& vectorOfString);

	public:
		GrepWorker(WorkingCreatingContext* creatingContext);
		void run() override;
	};

}
