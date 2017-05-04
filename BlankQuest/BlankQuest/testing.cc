#include "question.h"

#include <iostream>
#include <string>
#include <fstream>

void StartTesting(const std::string& filename)
{
	Question ques(filename);
	std::vector<bool> result;

	for (auto& q : ques.Get())
	{
		std::cout << "Q) " << std::get<0>(q) << std::endl << "A) ";

		std::string answer;
		std::getline(std::cin, answer);

		if (answer == std::get<1>(q))
		{
			result.push_back(true);
			std::cout << "¦¦¦¡ (O)";
		}
		else
		{
			result.push_back(false);
			std::cout << "¦¦¦¡ (X)";
		}

		std::cout << std::endl << std::endl;
	}

	std::ofstream file("result.txt");

	if (file.is_open())
	{
		size_t idx = 0;

		for (auto& r : result)
		{
			if (!r)
			{
				file << std::get<0>(ques.Get()[idx]) << " ¦¡ " << std::get<1>(ques.Get()[idx]) << std::endl;
			}

			++idx;
		}
	}

	file.close();
}