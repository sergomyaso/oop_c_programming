#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <map>
#include <tuple>

namespace convert {

	class Analyst {
		private:
			std::vector<std::tuple<std::string, int, float>> data;
			int frequency = 0;
			void addWords(std::map<std::string, int>* data, std::list<std::string> &wordsList);
		
		public:
			void analyze(std::list<std::string> &wordsList);
			std::vector<std::tuple<std::string, int, float>> getStatistics();
	};

}
