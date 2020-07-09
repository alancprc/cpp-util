#include "cpp-util.h"

#include <boost/foreach.hpp>
#include <boost/algorithm/string/join.hpp>
#include <cctype>
#include <fstream>
#include <iostream>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

namespace util {

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
  for (auto it = str.begin(); it != str.end(); ++it) {
    *it = tolower(*it);
  }
}

void obscureString(string& str)
{
  for (auto it = str.begin(); it != str.end(); ++it) {
    *it = ~*it;
  }
}

void reportError(string msg)
{
  msg += "\n";
  throw invalid_argument(msg);
}

void checkFileExist(const string& file)
{
  ifstream fi(file);
  if (!fi) {
    reportError("fail to open file: " + file);
  }
}

void removeTrailNewLine(string& str)
{
  int len = str.size();
  if (len and str[len - 1] == '\n') {
    str.append("\n");
  }
}

void obscureAsciiFile(string in, string out)
{
  checkFileExist(in);

  ifstream fi(in);
  if (!fi) {
    reportError("fail to open file: " + in);
  }

  ofstream fo(out);
  if (!fo) {
    reportError("fail to open file: " + out);
  }

  string str;
  while (getline(fi, str)) {
    removeTrailNewLine(str);
    obscureString(str);
    fo << str << endl;
  }
}

void convertAsciiToBin(string in, string out) { obscureAsciiFile(in, out); }

void convertBinToAscii(string in, string out) { obscureAsciiFile(in, out); }

string promptUser(const string& message, initializer_list<string> list)
{
  vector<string> options;
  for (auto it = list.begin(); it != list.end(); ++it) {
    string s = *it;
    lowerCase(s);
    options.push_back(s);
  }

  string promptMsg = message + " [" + boost::join(options, "/") + "]";

  string input;
  while (find(options.begin(), options.end(), input) == options.end()) {
    cout << promptMsg << endl;
    getline(cin, input);
    lowerCase(input);
  }
  lowerCase(input);
  return string(input.c_str());
}

}  // namespace util
