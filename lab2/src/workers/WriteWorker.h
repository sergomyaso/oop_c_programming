#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "WorkerInterface.h"
#include "WorkingCreatingContext.h"
#include "../exceptions/OpenFileException.h"

namespace workflow {

	class WriteWorker : public WorkerIntreface {
	private:
		std::string pathToFile;
		std::string* data;
		std::ofstream outFileStream;

	private:
		void open();
		void write();
		void close();
		
	public:
		WriteWorker(WorkingCreatingContext* creatingContext);
		void run() override;

	};

}
