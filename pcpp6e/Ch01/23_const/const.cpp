/*
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
const.cpp
*/

import std;
using namespace std;

void myStringFunction (const string* someString)
{
   // *someString = "test"; // 爆炸
    print("*someString={}", *someString);
}
int main() {
  /*
  In C++, programmers are encouraged to avoid #define in favor of
  using const to define constants. Defining a constant with const is just like
  defining a variable, except that the compiler guarantees that code cannot
  change the value. Here are some examples:
  */

  const int versionNumberMajor{2};
  const int versionNumberMinor{1};
  const string productName{"Super Hyper Net Modulator"};
  const double PI{3.141592653589793238462};

  int* ip;
  ip = new int[10];
  ip[4] = 5;

  /*

  To prevent the pointed-to values from being modified (as in the third
  statement), you can add the keyword const to the declaration of ip like this:
  const int* ip;
  ip = new int[10];
  ip[4] = 5; // DOES NOT COMPILE!
  C++ Crash Course ❘ 57
  Now you cannot change the values to which ip points. An alternative but
  semantically equivalent way to write this is as follows:

Putting the const before or after the int makes no difference in its
functionality.

  */

  int const* ip2;  // const* make sure that the content pointed by ip2 cannot be
                   // changed
                   // or const int* ip2;
  ip2 = new int[10];
  // ip2[4] = 5; //DOES NOT COMPILE!
  /*
  >  g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
const.cpp
./const.cpp: In function 'int main()':
./const.cpp:28:10: error: assignment of read-only location '*(ip2 + 16)'
   28 |   ip2[4] = 5;
      |   ~~~~~~~^~~

  */

  /*
  If you instead want to mark ip itself const (not the values to which it points), you need to write this:
  */
   int* const ip3 {nullptr};
 // ip3 = new int[10]; // DOES NOT COMPILE

  /*
  >  g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello const.cpp
./const.cpp: In function 'int main()':
./const.cpp:61:7: error: assignment of read-only variable 'ip3'
   61 |   ip3 = new int[10];
      |   ~~~~^~~~~~~~~~~~~

  */
 // ip3[4] = 5; //zsh: segmentation fault  ./hello


 int * const ip5 {new int [10]};
 ip5[4] = 5;
 println ("ip5[4]={}", ip5[4]);
 delete [] ip5;
println ("ip5[4]={} after delete[]", ip5[4]);

string 我的繩 {"The string"};

myStringFunction(&我的繩);
 
}