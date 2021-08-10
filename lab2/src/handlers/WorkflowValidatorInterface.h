#pragma once

namespace workflow {

	class WorkflowValidatorInterface {
	public:
		virtual bool isValidString(const std::vector<std::string>& argString) = 0;
		virtual bool isValidIndexSequence(const std::vector<int>& sequence) = 0;
		virtual bool isValidQueue(std::map<int, std::string>& mapWorkers, const std::vector<int> sequence) = 0;
	};

}
