#include <iostream>
#include <fstream>
#include <vector>

#include "src/include/UserContent.h"
#include "src/include/Randoms.h"

auto main(int argc, char** const argv) -> int {

	try {
		UserContent content{
			std::fstream{
				"../chrome/userContent.css",
				std::ios::in | std::ios::out
			}
			, Random<int>{ 0, 2 }
			, std::vector<std::string>{"1.jpg", "2.jpg", "3.jpg"}
			, "img/"
		};

		content.SearchPatternIdx();
		content.Change();
	}
	catch (const std::exception& exp) {
		std::cerr << exp.what();
	}

	return EXIT_SUCCESS;
}