#include "../cpp-util.h"

#include "gtest/gtest.h"
#include <iomanip>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <cmath>

using namespace std;
using namespace util;

TEST(promptUserTest, inputTest)
{
  set<string> expect{"quit", "y", "n"};
  istringstream iss("x\nb\ny\n");
  cin.rdbuf(iss.rdbuf());

  string answer = promptUser("continue?", "y", "n", "quit");
  EXPECT_EQ(answer, "y");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", "y", "n", "QUIT");
  EXPECT_EQ(answer, "quit");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", "y", "QUIT");
  EXPECT_EQ(answer, "quit");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", "QUIT");
  EXPECT_EQ(answer, "quit");
}

TEST(FunctionTest, lowerCaseTest)
{
  string upper = "THE BROWN FOX JUMPS OVER THE LAZY DOG";
  string lower = "the brown fox jumps over the lazy dog";
  lowerCase(upper);
  EXPECT_EQ(upper, lower);
}

TEST(FunctionTest, reportErrorTest)
{
  EXPECT_THROW(reportError("error"), std::invalid_argument);
}

TEST(FunctionTest, removeTrailNewLineTest)
{
  string str = "hello\n";
  removeTrailNewLine(str);
  EXPECT_NE(str, "hello");
}

TEST(FunctionTest, obscureAsciiFileTest)
{
  // create test file from string
  string str = "line1 1.2345\nline2 2.3456\nline3 3.1415\n";
  ofstream("input", ios_base::binary)  << str;

  obscureAsciiFile("input", "output");
  obscureAsciiFile("output", "inputrestore");

  // read file to string
  ifstream fs("inputrestore", ios_base::binary | ios_base::ate);
  auto size = fs.tellg();
  string restore(size, '\0');
  fs.seekg(0);
  fs.read(&restore[0], size);
  fs.close();
  system("rm -f input output inputrestore");
  EXPECT_EQ(str, restore);
}

TEST(promptUserTest, initializerTest)
{
  istringstream iss("x\nb\ny\n");
  cin.rdbuf(iss.rdbuf());

  string answer = promptUser("continue?", {"y", "n", "quit"});
  EXPECT_EQ(answer, "y");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", {"y", "n", "QUIT"});
  EXPECT_EQ(answer, "quit");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", {"y", "QUIT"});
  EXPECT_EQ(answer, "quit");

  iss.str("x\nb\nquit\n");
  cin.rdbuf(iss.rdbuf());
  answer = promptUser("continue?", {"QUIT"});
  EXPECT_EQ(answer, "quit");
}

