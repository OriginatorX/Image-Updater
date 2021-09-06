#include <stdexcept>
#include <fstream>
#include <random>

#include "include/UserContent.h"

UserContent::UserContent(std::fstream&& stream, 
						const Random<int>& random,
						const std::vector<std::string>& images, 
						const std::string& pattern)

	: stream_			{ std::move(stream) }
	, images_			{ images }
	, pattern_			{ pattern }
	, indexOfPattern_	{ 0 }
	, random_			{ random }
{
	if (!stream_)
		throw std::runtime_error("stream is nullptr");
	if (images.empty())
		throw std::runtime_error("images is empty");
}
 
size_t UserContent::SearchPatternIdx() {
	size_t	index				  = 0;
	size_t	numberOfStr			  = 0;
	size_t	sizeOfFileBeforeIndx  = 0;

	std::string currentStr;

	for (; std::getline(stream_, currentStr); ++numberOfStr) {

		if ((index = currentStr.find("images/")) != std::string::npos) 
			break;
		
		currentStr += '\0';
		sizeOfFileBeforeIndx += currentStr.size();
	}

	if (index == std::string::npos) 
		throw std::runtime_error("pattern wasn't found");

	indexOfPattern_ = sizeOfFileBeforeIndx + numberOfStr + index + pattern_.size();
	
	return indexOfPattern_;
}

void UserContent::Change() {
	stream_.seekg(indexOfPattern_, std::ios::beg);
	stream_ << images_[random_()];
}
