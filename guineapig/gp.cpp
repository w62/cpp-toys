#include <iostream>
// Type Alias for Function pointers:
//
// Based on page 353 - 354 of professional C++ 4th ed.
//
int add(int, int);
int sub(int, int);
int mul(int, int);

int main() {
  using IntFunction = int (*)(int, int);

  IntFunction IntFunc;

  IntFunc = add;
  std::cout << IntFunc(1, 2) << std::endl;

  IntFunc = sub;
  std::cout << IntFunc(3, 4) << std::endl;

  IntFunc = mul;
  std::cout << IntFunc(5, 6) << std::endl;

  return 0;
}

int add(int a, int b) {
  std::cout << "add" << std::endl;
  return a + b;
}

int sub(int a, int b) {
  std::cout << "sub" << std::endl;
  return a - b;
}

int mul(int a, int b) {
  std::cout << "mux" << std::endl;
  return a * b;
}
