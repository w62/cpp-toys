#include <iostream>



// C++20 
auto play (auto x, auto y)
{
    std::cout << '\n';
    std::cout << "x is:";
    std::cout << x;
    std::cout << '\n';
    std::cout << "y is:";
    std::cout << y;
    std::cout << '\n';
    return x;
}
int add(int x, int y) { return x + y; }

double add(double x, double y) { return x + y; }

int main() {
  std::cout << add(1, 2);  // calls int add
  std::cout << '\n';
  std::cout << add(1.2, 3.4);

  play(2,3);
  play('a', 'b');
  play(1.2, "hello world");
  play("hello baby", 1.32);

  return 0;
}
