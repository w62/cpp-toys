/*
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
const.cpp
*/

import std;

using namespace std;

void thirdPartyLibraryFunction(char* str) { println("char * str \"{}\"", str); }
void f(const char* str) { thirdPartyLibraryFunction(const_cast<char*>(str)); }

double divideNumbers(double numerator, double denominator) {
  if (denominator == 0) {
    throw invalid_argument{"Denominator cannot be 0."};
  }
  return numerator / denominator;
}

int main() {
  string str{"C++"};
  const string& constStr{as_const(str)};

  f("Hello C++");

  try {
    println("{}", divideNumbers(2.5, 0.5));
    println("{}", divideNumbers(2.3, 0));
    println("{}", divideNumbers(4.5, 2.5));
  } catch (const invalid_argument& exception) {
    println("麥田捕手🧠： 😃Exception caught: {}", exception.what());
  }
  using InterPtr = int*;
  typedef int* InterPtr2;
  int* p1;
  InterPtr p2;
  InterPtr2 p3;

  p1 = p2;
  p2 = p1;
  p3 = p1;
  println("here? 😉");

  int xxx{123};
  decltype(xxx) yyy{456};
  println("xxx={}", xxx);
  println("yyy={}", yyy);
}