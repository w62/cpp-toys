//#include <iostream>
import <iostream>;
/*
 * Note that if the nested block apples had not been defined, the name apples in
 * the nested block would still refer to the outer block apples, so the
 * assignment of value 10 to apples would have applied to the outer block
 * apples:
 */
int main() {     // outer block
  int apples{5}; // here's the outer block apples

  { // nested block
    // apples refers to outer block apples here
    std::cout << apples << '\n'; // print value of outer block apples

    // no inner block apples defined in this example

    apples = 10; // this applies to outer block apples

    std::cout << apples << '\n'; // print value of outer block apples
  } // outer block apples retains its value even after we leave the nested block

  std::cout << apples << '\n'; // prints value of outer block apples

  return 0;
} // outer block apples destroyed
/** 
> make main
clang++ -std=c++20 -ggdb -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror  -o main main.cpp add.cpp
./main
5
10
10
*/
