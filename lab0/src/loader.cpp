#include "loader.h"

namespace convert {

	 PathException::PathException(const std::string error) {
		this->error = error;
	}

	const std::string PathException::getError()const {
		return this->error;
	}


	Loader::Loader() {
		this->pathToInput = constants::defoultInPath;
	}

	Loader::Loader(std::string pathToInput) {
		this->pathToInput = pathToInput;
	}

	void Loader::open() {
		this->inStream.open(this->pathToInput);
		if (!this->inStream) {
			throw PathException("Bad path");
		}
	}

	std::list<std::string> Loader::getWords(std::string line) {
		std::list<std::string> wordsList;
		std::string word = "";
		for (auto it : line) {
			if (isalpha((unsigned char)it) || isdigit((unsigned char) it)) {
				word += it;
			}
			else {
				wordsList.push_back(word);
				word = "";
			}
		}
		wordsList.push_back(word);
		return wordsList;
	}

	std::list<std::string> Loader::getData() {
		std::list<std::string> wordsList;
		while (!this->inStream.eof()) {
			std::string line;
			getline(this->inStream, line);
			std::list <std::string> wordsFromString = this->getWords(line);
			wordsList.insert(wordsList.end(), wordsFromString.begin(), wordsFromString.end());
		}
		return wordsList;
	}

	void Loader::close() {
		this->inStream.close();
	}
}
