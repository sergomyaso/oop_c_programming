#include "WorkflowValidator.h"

namespace workflow {

	WorkflowValidator::WorkflowValidator() {
		this->workerArgMap["readfile"] = this->READ_FILE_ARGS;
		this->workerArgMap["writefile"] = this->WRITE_FILE_ARGS;
		this->workerArgMap["sort"] = this->SORT_FILE_ARGS;
		this->workerArgMap["grep"] = this->GREP_FILE_ARGS;
		this->workerArgMap["replace"] = this->REPLACE_FILE_ARGS;
		this->workerArgMap["dump"] = this->DUMP_FILE_ARGS;
	}

	bool WorkflowValidator::isValidString(const std::vector<std::string>& argString) {
		if (this->workerArgMap.find(argString[Parser::INDEX_WORKER_NAME]) != this->workerArgMap.end()) {
			if (this->workerArgMap[argString[Parser::INDEX_WORKER_NAME]] == ((argString.size() - 1) - Parser::COUNT_NOT_USEFUL_ARG));
			return true;
		}
		return false;
	}

	bool WorkflowValidator::isValidIndexSequence(const std::vector<int>& sequence) {
		std::set<int> cloneSequence(sequence.begin(), sequence.end());
		return (cloneSequence.size() == sequence.size());
	}

	bool WorkflowValidator::isValidQueue(std::map<int, std::string>& mapWorkers, const std::vector<int> sequence) {
		auto beginWorker = workflow::splitString<std::string>(mapWorkers[sequence[0]], Parser::SEPARETOR);
		auto lastWorker = workflow::splitString<std::string>(mapWorkers[sequence[sequence.size() - 1]], Parser::SEPARETOR);
		if (beginWorker[Parser::INDEX_WORKER_NAME] == "readfile" && lastWorker[Parser::INDEX_WORKER_NAME] == "writefile")
			return true;
		return false;
	}

}