import std;
using namespace std;

optional<int> getData(bool giveIt) {
  if (giveIt) {
    return 42;
  }
  return nullopt;
}

int sum(initializer_list<int> values) {
  int total{0};
  for (int value : values) {
    total += value;
  }
  return total;
}

int main() {
  array<int, 3> arr{9, 8, 7};
  println("Array size = {}", arr.size());
  println("arr 2nd element = {}", arr[1]);

  /*
  myVector is declared as vector<int>. The angle brackets are required to
  specify the template arguments, just as with std::array. A vector is a generic
  container. It can contain almost any type of object, but all elements in a
  vector must be of the same type. This type is specified between the angle
  brackets. Templates are discussed in detail in Chapter 12 and Chapter 26,
  “Advanced Templates.”
  */
  vector<int> myVector{11, 22};
  myVector.push_back(33);
  myVector.push_back(44);
  println();
  println("myVector 1st element: {}", myVector[0]);
  println("The entire myVector: {}", myVector);

  pair<double, int> myPair{1.23, 5};
  println();
  println("{} {}", myPair.first, myPair.second);
  println("the entire myPair: {}", myPair);
  println();
  optional<int> data1{getData(true)};
  optional<int> data2{getData(false)};

  println("data1.has_value = {}. value = {}", data1.has_value(), *data1);
  println("data1 = {}", *data1);
  /*
  runtime error:
  /opt/homebrew/Cellar/gcc/15.1.0/include/c++/15/optional:1186: constexpr _Tp&
std::optional<_Tp>::operator*() & [with _Tp = int]: Assertion
'this->_M_is_engaged()' failed. zsh: abort      ./hello


  println("data2 = {}", *data2);
  */
  if (!data2) {
    println("data2 has no value");
  }

  /* structure bindings*/

  /*
  Assume you have the following std::array:
array values { 11, 22, 33 };
You can declare three variables, x, y, and z, initialized with the three values
from the array as follows. You have to use the auto keyword for structured
bindings, i.e., you cannot, for example, specify int instead of auto. auto [x,
y, z] { values };
  */

  array values{11, 22, 33};
  auto [a, b, c]{values};
  println("x={}, y={}, z={}", a, b, c);

  for (int j : arr) {
    println("{}", j);
  }
  struct Point {
    double m_x, m_y, m_z;
  };
  Point point;
  point.m_x = 1.0;
  point.m_y = 2.0;
  point.m_z = 3.0;
  auto [x, y, z]{point};

  pair myPair2{"hello", 5};
  auto [theString, theInt]{myPair2};  // Decompose using structured bindings.
  println("theString: {}", theString);
  println("theInt: {}", theInt);

  /*
  Initializers for Range-Based for Loops
You can use initializers with range-based for loops, similar to initializers for
if and switch statements. The syntax is as follows: for (<initializer>;
<range-declaration> : <range-expression>) { <body> } Any variables introduced in
the <initializer> are available only in the <range-declaration>, the
<range-expression> and in the <body>. They are not available outside the
range-based for loop. Here is an example: for (array arr { 1, 2, 3, 4 }; int i :
arr) { println("{}", i); }
  */
  for (array arr4{1, 2, 3, 4}; int i : arr4) {
    println("{}", i);
  }

  /*

  compile error
  ./avp.cpp:84:22: error: 'arr4' was not declared in this scope; did you mean
  'arr'? 84 |   println("arr4={}", arr4); |                      ^~~~ | arr


    println("arr4={}", arr4);
    */

  int v1{sum({1, 2, 3})};
  int v2{sum({10, 20, 30, 40, 50, 60})};

  println("v1={}", v1);
  println("v2={}", v2);

  string myString{"Hello, World"};
  println("The value of myString is {}", myString);
  println("The second letter is {}", myString[1]);

  return 0;
}