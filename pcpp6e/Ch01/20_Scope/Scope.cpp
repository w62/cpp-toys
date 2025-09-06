/*
 g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
 Scope.cpp
*/

import std;           //  指定動作
using namespace std;  //  指定動作

class Demo {
 public:
  int get() { return 5; }
};

int get() { return 10; }

namespace NS {
int get() { return 20; }

}  // namespace NS

struct CircleStruct {
  int x, y;
  double radius;
};

class CircleClass {
 public:
  CircleClass(int x, int y, double radius) : m_x{x}, m_y{y}, m_radius{radius} {}

 private:
  int m_x, m_y;
  double m_radius;
};

class MyClass {
 public:
  MyClass() : m_array{0, 1, 2, 3} {}

 private:
  int m_array[4];
};

struct Employee {
  char firstInitial;
  char lastInitial;
  int employeeNumber;
  int salary{75'000};
};

int main() {
  Demo d;

  CircleStruct myCircle5{10, 10, 2.5};
  CircleClass myCircle6{10, 10, 2.5};

  int i{10};

  int* myIntPointer{nullptr};

  Employee anEmployee{'J', 'D', 0, 80'000};

  Employee anotherEmployee{.firstInitial = 'R', .lastInitial = 'J'};

  println("{}", d.get());
  println("{}", NS::get());
  println("{}", ::get());
  println("{}", get());

  println("anEmployee {}", anEmployee.salary);
  println("anotherEmployee {}", anotherEmployee.lastInitial);

  myIntPointer = new int;

  *myIntPointer = 8;

  // println ("myIntPointer = {}", myIntPointer); // 爆炸！
  println("*myIntPointer = {}", *myIntPointer);

  /*
  After you are finished with your dynamically allocated memory, you need to
deallocate the memory using the delete operator. To prevent the pointer from
being used after having deallocated the memory it points to, it’s recommended to
set it to nullptr:
  */
  delete myIntPointer;
  myIntPointer = nullptr;

  int i2{9};
  int* myIntPointer2{&i2};

  println("*myIntPointer2 = {}", *myIntPointer2);

  int arraySize{8};
  int* myVariableSizedArray{new int[arraySize]};
  // This allocates enough memory to hold arraySize integers.

  myVariableSizedArray[3] = 2;

  // println("myVariableSizedArray = {}", myVariableSizedArray); // 爆炸！
  println("myVariableSizedArray = {}", myVariableSizedArray[3]);
  delete[] myVariableSizedArray;
  myVariableSizedArray = nullptr;

  /*
  When your code is done with the array, it should remove the array from the
free store so that other variables can use the memory. In C++, you use the
delete[] operator to do this: delete[] myVariableSizedArray;
myVariableSizedArray = nullptr;
The brackets after delete indicate that you are deleting an array!
  */
  return 0;
}
