#include "loader.h"
#include "analyst.h"
#include "tableMaker.h"

namespace convert {
	void showHelp() {
		std::cout << "use --help for show help " << std::endl << std::endl;
		std::cout << "Without parameters:  defoult input file path(...\\input.txt), output file path(...\\output.txt)" << std::endl;
		std::cout << "With two parameters: <path to input file> <path to output file>" << std::endl;
	}
}

int main(int argc, char* argv[]) {
	setlocale(0, "");
	const int InputFileArgIndex = 1;
	const int OutputFileArgIndex = 2;

	const int NOT_ARGUMENT = 1;
	const int PARAMS = 3;
	if (argc == NOT_ARGUMENT) {
		convert::Loader loader;
		convert::Analyst analystObj;
		convert::TableMaker tableMaker;
		try {
			loader.open();
		}
		catch (convert::PathException& exception) {
			std::cerr << exception.getError();
			return 1;
		}
		analystObj.analyze(loader.getData());
		loader.close();
		tableMaker.makeTable(analystObj.getStatistics());

		return 0;
	}
	
	if (argc == PARAMS) {
		const std::string pathToInput = std::string(argv[InputFileArgIndex]);
		const std::string pathToOutput = std::string(argv[OutputFileArgIndex]);

		convert::Loader loader(pathToInput);
		convert::Analyst analystObj;
		convert::TableMaker tableMaker(pathToOutput);
		try {
			loader.open();
		}
		catch (convert::PathException &exception) {
			std::cerr << exception.getError();
			return 1;
		}
		analystObj.analyze(loader.getData());
		loader.close();
		tableMaker.makeTable(analystObj.getStatistics());

		return 0;
	}
	
	convert::showHelp();

	return 0;
}
