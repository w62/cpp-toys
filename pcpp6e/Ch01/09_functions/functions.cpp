/*
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
functions.cpp
*/

import std;
using namespace std;

/*
Function Return Type Deduction
You can ask the compiler to figure out the return type of a function
automatically. To make use of this functionality, just specify auto as the
return type.
*/

/* function overloading */
auto addNumbers(int number1, int number2) {
  println("Current function name:{}, int", __func__);
  return number1 + number2;
}

auto addNumbers(double number1, double number2) {
  println("Current function name:{}, double", __func__);
  return number1 + number2;
}

/*
> g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
functions.cpp
./functions.cpp: In function 'int main()':
./functions.cpp:32:7: warning: ignoring return value of 'int func()', declared
with attribute 'nodiscard' [-Wunused-result] 32 |   func(); |   ~~~~^~
./functions.cpp:27:19: note: declared here
   27 | [[nodiscard]] int func() { return 42; }
      |                   ^~~~

*/
[[nodiscard]] int func() { return 42; }
/*
no warning for [[maybe_unused]]
*/
int func2(int param1, [[maybe_unused]] int param2) {
    return 53;
}

unt func3 (int x) {
    [[asume(x>=0)]]; //C++23 
    return x/32;
}

int main() {
  println("Current function name:{}", __func__);
  println("addNumbers(4,5) result {}", addNumbers(4, 5));
  println(" addNumbers(2.22, 8.88) result {}", addNumbers(2.22, 8.88));
  func();
  func2(1,3);
  
}
