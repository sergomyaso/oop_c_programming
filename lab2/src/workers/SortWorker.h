#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "WorkerInterface.h"
#include "WorkingCreatingContext.h"

namespace workflow {

	class SortWorker : public WorkerIntreface {

	private:
		std::string* data;
		static const char SEPARATOR = '\n';

	private:
		std::vector <std::string> splitString(char separator);
		void sortLexic(std::vector<std::string>& str);
		void setStringFromVector(const std::vector<std::string>& vectorOfString);

	public:
		SortWorker(WorkingCreatingContext* creatingContext);
		void run() override;
		
	};

}
