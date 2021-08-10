#include "ReplaceWorker.h"

namespace workflow {

	std::string ReplaceWorker::replaceWord() {
		std::regex rx(this->findWord.c_str());
		return std::regex_replace(*this->data, rx, this->toChangeWord);
	}

	ReplaceWorker::ReplaceWorker(WorkingCreatingContext* creatingContext) {
		this->findWord = creatingContext->arg1;
		this->toChangeWord = creatingContext->arg2;
		this->data = creatingContext->data;
		delete creatingContext;
	}

	void ReplaceWorker::run() {
		*data = this->replaceWord();
	}

}
