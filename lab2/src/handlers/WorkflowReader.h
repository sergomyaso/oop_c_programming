#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

#include "WorkflowValidator.h"
#include "WorkflowReaderInterface.h"
#include "../exceptions/OpenFileException.h"
#include "../exceptions/ValidFileException.h"

namespace workflow {

	class WorkflowReader : public WorkflowReaderInterface {
	private:
		 const std::string WORKER_FLAG = "desc";
		 const std::string INDEX_FLAG = "csed";
		 const std::string INDEX_SEPARATOR = " -> ";

		std::string pathToFile;
		std::ifstream inputFileStream;

	private:
		std::vector <int> splitIndexes(const std::string& lineIndexes, const std::string separator);
		std::map<int, std::string> getMapOfWorkers();
		std::string getSequenceOfIndexes();
		std::queue<std::string> createQueue(std::map<int, std::string> mapOfWorkers, std::vector <int>& workerOrder);
		void open();
		void close();

	public:
		WorkflowReader(const std::string pathToFilfe);
		std::queue<std::string> getWorkerQueue() override;
	};

}

