#include "WorkflowReader.h"

namespace workflow {
	WorkflowReader::WorkflowReader(const std::string pathToFile) {
		this->pathToFile = pathToFile;
	}

	void WorkflowReader::open() {
		this->inputFileStream.open(this->pathToFile);
		if (!this->inputFileStream.is_open()) {
			auto context = new WorkflowExceptionContext("Input file opening error");
			throw OpenFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
	}

	void WorkflowReader::close() {
		this->inputFileStream.close();
	}

	std::vector<int> WorkflowReader::splitIndexes(const std::string& lineIndexes, const std::string separator) {
		std::vector<int> indexes;
		int tokensInSepator = separator.size();
		for (size_t i = 0; i < lineIndexes.size(); i++) {
			if (lineIndexes[i] == separator[0])
				i += (tokensInSepator - 1);
			else
				indexes.push_back(int(lineIndexes[i]));
		}
		return indexes;
	}

	std::map<int, std::string> WorkflowReader::getMapOfWorkers() {
		std::map<int, std::string> stringsWorkers;
		std::string line;
		std::getline(this->inputFileStream, line);
		if (line == this->WORKER_FLAG) {
			while (line != this->INDEX_FLAG) {
				std::getline(this->inputFileStream, line);
				stringsWorkers[int(line[0])] = line;
			}
		}
		return stringsWorkers;
	}

	std::string WorkflowReader::getSequenceOfIndexes() {
		std::string sequence;
		std::getline(this->inputFileStream, sequence);
		return sequence;
	}

	std::queue<std::string> WorkflowReader::createQueue(std::map<int, std::string> mapOfWorkers, std::vector <int>& workerOrder) {
		std::queue<std::string> queueWorker;
		for (auto index : workerOrder) {
			queueWorker.push(mapOfWorkers[index]);
		}
		return queueWorker;
	}

	std::queue<std::string> WorkflowReader::getWorkerQueue() {
		this->open();
		std::map<int, std::string> mapOfWorkers = this->getMapOfWorkers();
		std::string sequence = this->getSequenceOfIndexes();
		this->close();				
		std::vector <int> workerOrder = this->splitIndexes(sequence, this->INDEX_SEPARATOR);

		WorkflowValidator validator;
		if (!validator.isValidIndexSequence(workerOrder)) {
			auto context = new WorkflowExceptionContext("There are duplicate indexes");
			throw ValidFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		if (!validator.isValidQueue(mapOfWorkers, workerOrder)) {
			auto context = new WorkflowExceptionContext("Problem with readfile or writefile");
			throw ValidFileException(std::auto_ptr<WorkflowExceptionContext*>(&context));
		}
		std::queue<std::string> queueWorker = this->createQueue(mapOfWorkers, workerOrder);
		return queueWorker;
	}

}
