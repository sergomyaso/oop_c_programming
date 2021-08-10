#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

namespace workflow {

	template <typename T>
	T convertToTemplateType(std::string& str) {
		std::istringstream ss(str);
		T converted;
		ss >> converted;
		return converted;
	}

	template <typename T>
	std::vector<T> splitString(const std::string& data, const char separator) {
		std::vector<T> splitedString;
		std::stringstream stringStream;
		stringStream.str(data);
		std::string item;
		while (std::getline(stringStream, item, separator)) {
			splitedString.push_back(workflow::convertToTemplateType<T>(item));
		}
		return splitedString;
	}

}
