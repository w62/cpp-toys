/*
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello spaceship.cpp
If the operands are integral types, the result is a strong
ordering and can be one of the following:
➤➤ strong_ordering::less: First operand less than second
➤➤ strong_ordering::greater: First operand greater than second
➤➤ strong_ordering::equal: First operand equal to second

*/

import std;
using namespace std;
int main() {
  int i{11};
  strong_ordering result{i <=> 8};
  if (result == strong_ordering::less) {
    println("less");
  }
  if (result == strong_ordering::greater) {
    println("greater");
  }
  if (result == strong_ordering::equal) {
    println("equal");
  }
}