#pragma once

#include <iostream>
#include <string.h>

#include "../workers/WorkingCreatingContext.h"

namespace workflow {
	
	class ParserInterface {
	public:
		virtual WorkingCreatingContext* parse(std::string data) = 0;
	};

}
