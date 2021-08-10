#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "ParserInterface.h"
#include "../workers/WorkingCreatingContext.h"
#include "WorkflowValidator.h"
#include "../exceptions/ValidFileException.h"
#include "../workers/WorkflowFunctions.h"

namespace workflow {

	class Parser : public ParserInterface {
	private:
		static const char SEPARETOR = ' ';
		const std::string DEFOULT_ARG = "";

		static const size_t COUNT_NOT_USEFUL_ARG = 2;

		static const size_t INDEX_WORKER_NAME = 2;
		static const size_t INDEX_FIRST_ARG = 3;
		static const size_t INDEX_SECOND_ARG = 4;

		static const size_t SIZE_WITHOUT_PARAMS = 3;
		static const size_t SIZE_ONE_PARAM = 4;
		static const size_t SIZE_TWO_PARAMS = 5;
		friend class WorkflowValidator;
		std::string* data;

	public:
		Parser(std::string* data);
		WorkingCreatingContext* parse(std::string line) override;
	};

}
