#include "TestFunction.h"

	void workflow::insertStringInFile(std::string str, std::string pathToFile) {
		std::ofstream outFileStream(pathToFile);
		if (!outFileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Open file error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		outFileStream << str;
		outFileStream.close();
	}

	bool workflow::isFileEQ(std::string pathToFile1, std::string pathToFile2) {
		std::ifstream fileStream1(pathToFile1);
		std::ifstream fileStream2(pathToFile2);

		if (!fileStream1.is_open() || !fileStream2.is_open()) {
			auto context = new WorkflowExceptionContext("Open file error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		std::ostringstream oss;

		oss << fileStream1.rdbuf();
		auto dataFromFile1 = oss.str();
		oss.clear();

		oss << fileStream2.rdbuf();
		auto dataFromFile2 = oss.str();

		fileStream1.close();
		fileStream2.close();
		return (dataFromFile1 == dataFromFile2);
	}

	std::string workflow::getStringFromFile(std::string pathToFile) {
		std::ifstream fileStream(pathToFile);
		if (!fileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Open file error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		std::ostringstream oss;
		oss << fileStream.rdbuf();
		auto dataFromFile = oss.str();
		fileStream.close();
		return dataFromFile;
	}
