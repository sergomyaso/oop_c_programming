#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>

namespace convert {
	
	namespace constants {
		static const std::string tablePattern = "Word;Frequency;Percent";
		static const std::string defoultOutPath = "output.csv";
	}

	class TableMaker {
		private:
			std::string pathToOutput;

		public:
			TableMaker();
			TableMaker(std::string pathToOutput);
			void makeTable(std::vector<std::tuple<std::string, int, float>> data);
	};
}
