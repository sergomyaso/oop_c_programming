#include "WorkingCreatingContext.h"

namespace workflow {

	WorkingCreatingContext::WorkingCreatingContext(std::string* data, const std::string arg1, const std::string arg2, std::string workerName) {
		this->arg1 = arg1;
		this->arg2 = arg2;
		this->data = data;
		this->workerName = workerName;
	}

}
