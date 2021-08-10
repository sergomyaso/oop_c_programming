#pragma once
#include <queue>

namespace workflow {

	class WorkflowReaderInterface {
	public:
		virtual std::queue<std::string> getWorkerQueue() = 0;

	};

}