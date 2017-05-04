#include "question.h"

#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>

Question::Question(const std::string& filename)
{
	std::ifstream file(filename, std::ios::in);

	if (file.is_open())
	{
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);

			std::vector<std::string> tokens;
			boost::split(tokens, line, boost::is_any_of("|"));

			questions_.push_back(std::make_tuple(tokens[0], tokens[1]));
		}
	}
	else
	{
		throw std::runtime_error("Cannot open file");
	}

	file.close();
}

const std::vector<QuestionPair>& Question::Get() const
{
	return questions_;
}
