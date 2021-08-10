#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "../exceptions/WorkflowExceptionContext.h"
#include "../exceptions/OpenFileException.h"

namespace workflow {

	void insertStringInFile(std::string str, std::string pathToFile);
	bool isFileEQ(std::string pathToFile1, std::string pathToFile2);
	std::string getStringFromFile(std::string pathToFile);

}
