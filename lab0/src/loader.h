#pragma once

#include <iostream>
#include "loader.h"
#include <list>
#include <string>
#include <fstream>
#include <cctype>
#include <string>

namespace convert {

	namespace constants {
		static const std::string defoultInPath = "input.txt";
	}


	class PathException {
	/*Class exception for path to input*/
	private:
		std::string error;
	public:
		explicit PathException(const std::string error);
		const std::string getError()const;
	};

	class Loader {
		private:
			std::list<std::string> data;
			std::string pathToInput;
			std::ifstream inStream;
			std::list<std::string> getWords(std::string);

		public:
			Loader();
			Loader(std::string pathToInput);
			void open();
			std::list<std::string> getData();
			void close();
	};
}
