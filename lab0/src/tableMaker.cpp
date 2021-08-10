#include "tableMaker.h"

namespace convert {
	
	TableMaker::TableMaker() {
		this->pathToOutput = constants::defoultOutPath;
	}

	TableMaker::TableMaker(std::string pathToOutput) {
		this->pathToOutput = pathToOutput;
	}

	void TableMaker::makeTable(std::vector<std::tuple<std::string, int, float>> data) {
		std::ofstream fout(this->pathToOutput);
		fout << constants::tablePattern << std::endl;
		for (auto it = begin(data); it != end(data); ++it) {
			fout << std::get<0>((*it)) << ";" << std::get<1>((*it)) << ";" << std::get<2>((*it)) << std::endl;
		}
		fout.close();

	}
}
