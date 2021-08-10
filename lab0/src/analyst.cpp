#include "analyst.h"

namespace convert {

	bool tupleSort(std::tuple<std::string, int, float> const& a, std::tuple<std::string, int, float> const& b) {
		/* Auxiliary function for comparing pairs */
		return std::get<1>(a) > std::get<1>(b);
		
	}

	void Analyst::addWords(std::map<std::string, int>* data, std::list<std::string> &wordsList) {
		for (auto word : wordsList) {
			if ((*data).find(word) == (*data).cend()) {
				(*data)[word] = 0;
			}
			(*data)[word]++;
			this->frequency++;
		}
		(*data).erase("\0");
	}

	void Analyst::analyze(std::list<std::string> &wordsList) {
		std::map<std::string, int> data;
		this->addWords(&data, wordsList);

		std::string key = "";
		/* Iterating on pairs */
		for (std::pair<std::string, int> pair : data) {
			if (key != "")
				data.erase(key); // Deleting from data after pushing
			float percent = float(pair.second) / (this->frequency - 1) * 100;
			this->data.push_back(std::tuple<std::string, int, float>(pair.first, pair.second, percent));
			key = pair.first;
		}

		/*Sorting vector with data*/
		stable_sort(this->data.begin(), this->data.end(), &tupleSort);
	}

	std::vector<std::tuple<std::string, int, float>> Analyst::getStatistics() {
		return this->data;
	}

}
