#include <iostream>

void add2(int x) {
  x += 2;
  std::cout << x << '\n';
}

int main() {
  int a;
  a = 4;
  add2(a);
  std::cout << "a: " << a << '\n';

  return 0;
}
