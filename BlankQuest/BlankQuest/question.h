#pragma once

#include <vector>
#include <tuple>

using QuestionPair = std::tuple<std::string, std::string>;

class Question
{
public:
	Question(const std::string& filename);

	const std::vector<QuestionPair>& Get() const;

private:
	std::vector<QuestionPair> questions_;
};
