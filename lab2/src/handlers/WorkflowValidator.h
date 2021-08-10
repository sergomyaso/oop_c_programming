#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <queue>

#include "Parser.h"
#include "../workers/WorkingCreatingContext.h"
#include "../workers/WorkflowFunctions.h"
#include "WorkflowValidatorInterface.h"

namespace workflow {

	class WorkflowValidator : public WorkflowValidatorInterface {
	private:
	static const size_t READ_FILE_ARGS = 1;
	static const size_t WRITE_FILE_ARGS = 1;
	static const size_t SORT_FILE_ARGS = 0;
	static const size_t REPLACE_FILE_ARGS = 2;
	static const size_t DUMP_FILE_ARGS = 1;
	static const size_t GREP_FILE_ARGS = 1;
	std::map<std::string, int> workerArgMap;
	
	public:
		WorkflowValidator();
		bool isValidString(const std::vector<std::string>& argString) override;
		bool isValidIndexSequence(const std::vector<int>& sequence) override;
		bool isValidQueue(std::map<int, std::string>& mapWorkers, const std::vector<int> sequence ) override;
	};

}
