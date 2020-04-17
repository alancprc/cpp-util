#pragma once

#include <set>
#include <string>

/** @brief remove white space at the beginning/end of given string.*/
std::string removeWhiteSpace(const std::string& str);

/** @brief get user input until get expected answers.*/
std::string promptUser(const std::string& message, std::string answer);

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2);

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2, std::string answer3);

void lowerCase(std::string& str);
