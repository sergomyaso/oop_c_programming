#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "WorkerInterface.h"
#include "WorkingCreatingContext.h"
#include "../exceptions/OpenFileException.h"

namespace workflow {

	class ReadWorker : public WorkerIntreface {
	private:
		std::string pathToFile;
		std::string* inputDate;
		std::ifstream inputFileStream;

	private:
		void open();
		void read();
		void close();

	public:
		ReadWorker(WorkingCreatingContext* creatingContext);
		void run() override;
	};

}
