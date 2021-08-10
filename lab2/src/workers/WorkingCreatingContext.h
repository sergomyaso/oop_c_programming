#pragma once

#include <iostream>
#include <string>

namespace workflow {

	class WorkingCreatingContext {
	public:
		std::string workerName;
		std::string* data;
		std::string arg1;
		std::string arg2;
	
	public:
		WorkingCreatingContext(std::string* data, const std::string arg1, const std::string arg2, std::string workerName);
	};
}
