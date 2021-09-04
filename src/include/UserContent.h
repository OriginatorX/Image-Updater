#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <vector>

#include "Randoms.h"

class UserContent final {
public:
	UserContent(std::fstream&& stream,
				const Random<int>& random,
				const std::vector<std::string>& images, 
				const std::string& pattern);
public:
	size_t		searchPatternIdx();
	void		changeContent();
private:
	std::fstream			 stream_;
	std::vector<std::string> images_;

	std::string		pattern_;
	size_t			indexOfPattern_;
	Random<int>		random_;
};
