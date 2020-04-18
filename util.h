#pragma once

#include <set>
#include <string>

namespace util {

/** @brief remove white space at the beginning/end of given string.*/
std::string removeWhiteSpace(const std::string& str);

/** @brief get user input until get expected answers.*/
std::string promptUser(const std::string& message, std::string answer);

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2);

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2, std::string answer3);

void lowerCase(std::string& str);

void reportError(std::string msg);

void checkFileExist(const std::string& file);

void removeTrailNewLine(std::string& str);

void obscureAsciiFile(std::string in, std::string out);

void convertAsciiToBin(std::string in, std::string out);

void convertBinToAscii(std::string in, std::string out);

}  // namespace util
