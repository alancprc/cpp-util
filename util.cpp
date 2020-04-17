#include "util.h"

#include <boost/foreach.hpp>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string removeWhiteSpace(const string& str)
{
  string newStr(str);
  newStr.erase(0, newStr.find_first_not_of(" \t\r\n"));
  newStr.erase(newStr.find_last_not_of(" \t\r\n") + 1);
  return newStr;
}

std::string promptUser(const std::string& message, std::string answer)
{
  string input;
  lowerCase(answer);
  while (input != answer) {
    printf("%s [%s] ", message.c_str(), answer.c_str());
    getline(cin, input);
    lowerCase(input);
  }
  lowerCase(input);
  return string(input.c_str());
}

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2)
{
  string input;
  lowerCase(answer1);
  lowerCase(answer2);
  while (input != answer1 and input != answer2) {
    printf("%s [%s/%s] ", message.c_str(), answer1.c_str(), answer2.c_str());
    getline(cin, input);
    lowerCase(input);
  }
  lowerCase(input);
  return string(input.c_str());
}

std::string promptUser(const std::string& message, std::string answer1,
                       std::string answer2, std::string answer3)
{
  string input;
  lowerCase(answer1);
  lowerCase(answer2);
  lowerCase(answer3);
  while (input != answer1 and input != answer2 and input != answer3) {
    printf("%s [%s/%s/%s] ", message.c_str(), answer1.c_str(), answer2.c_str(),
           answer3.c_str());
    getline(cin, input);
    lowerCase(input);
  }
  lowerCase(input);
  return string(input.c_str());
}

void lowerCase(string& str)
{
  for (string::iterator it = str.begin(); it != str.end(); ++it) {
    *it = tolower(*it);
  }
}
