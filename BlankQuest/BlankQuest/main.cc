#include "question.h"

#include <boost/filesystem.hpp>
#include <iostream>
#include <stdlib.h>

extern void StartTesting(const std::string& filename);

int main()
{
	namespace filesystem = boost::filesystem;
	
	std::cout << "[������ ���]" << std::endl;
	for (filesystem::directory_iterator it = filesystem::directory_iterator("./data"); it != filesystem::directory_iterator(); ++it)
	{
		if (filesystem::is_regular_file(it->path()))
		{
			std::cout << it->path().generic_string() << std::endl;
		}
	}

	std::cout << "������ �����Ͻðڼ�?" << std::endl;

	std::string fname;
	std::getline(std::cin, fname);

	system("cls");

	StartTesting("./data/" + fname);

	return 0;
}
