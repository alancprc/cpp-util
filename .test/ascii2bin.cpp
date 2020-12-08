#include "../cpp-util.h"

#include <iostream>

using namespace std;
using namespace util;

int main(int argc, char** argv)
{
  for (int i = 1; i < argc; ++i) {
    string src = argv[i];
    string target = src + ".out";
    obscureAsciiFile(src, target);
  }
}

