#include "util.h"

#include "gtest/gtest.h"
#include <sstream>

using namespace std;

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
