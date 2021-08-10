#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "WorkerInterface.h"
#include "WorkingCreatingContext.h"

namespace workflow {

	class ReplaceWorker : public WorkerIntreface {
	private:
		std::string findWord;
		std::string toChangeWord;
		std::string* data;

	private:
		std::string replaceWord();

	public:
		ReplaceWorker(WorkingCreatingContext* creatingContext);
		void run() override;
	};

}
