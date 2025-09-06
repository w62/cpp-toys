/*
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello reference.cpp
*/

import std;

using namespace std;

string getString() { return "Hello world!"; }

template <typename T>
void print_type( const T& var) {
    print("The type is: {}", typeid(var).name());
    if (is_lvalue_reference<T>::value)
    {
        println("&");
    }
    else
    {
        println();
    }
}
class MyClass
{
    public:
    MyClass(int& ref): m_ref{ref} {}
     void PrintRef() const {
        println("m_ref is {}", m_ref);

    }
    private:
    int& m_ref;
};

void ptrRef1() {
  int* intP{nullptr};
  int*& ptrRef{intP};
  ptrRef = new int;
  *ptrRef = 5;

  println("ptrRef1 *ptrRef = 5;");
  println("* intP={}", *intP);
  println("* ptrRef={}", *ptrRef);

  delete ptrRef;
  ptrRef = nullptr;
}
void ptrRef2() {
  int* intP{nullptr};
  int*& ptrRef{intP};
  ptrRef = new int;
  *intP = 8;

  println("ptrRef2 *intP = 8;");
  println("* intP={}", *intP);
  println("* ptrRef={}", *ptrRef);


  delete ptrRef;
  ptrRef = nullptr;
}

void swap (int& first, int& second){

    int temp {first}; // deref first, put first's value into temp
    first = second; 
    second = temp; // treat temp as ref, put temp's value into second
    print_type(first);
    print_type(second);
    print_type(temp);
}
   void printString( const string& myString) { println("{}", myString); }
    
void seperateOddsAndEvens (const vector<int>& arr, vector<int>& odds, vector<int>& evens)
{
    for (int i: arr) {
        if (i%2 ==1) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
}

struct OddsAndEvens {
    vector<int> odds, evens;
};

OddsAndEvens seperateOddsAndEvens (const vector<int>& arr)
{
    vector<int> odds, evens;
    for (int i:arr) {
        if (i%2 ==1) {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
    return OddsAndEvens {.odds = odds, .evens = evens};
}
int main() {
  /*
  Attaching & to a type indicates that the variable is a reference. It is still
used as though it was a normal variable, but behind the scenes, it is really a
pointer to the original variable. Both the variable x and the reference variable
xRef point to exactly the same value; i.e., xRef is just another name for x. If
you change the value through either one of them, the change is visible through
the other one as well.
  */

  /*

  WARNING A reference variable must always be initialized when it’s created.

  WARNING Once a reference is initialized to refer to a specific variable, you
cannot change the reference to refer to another variable; you can change only
the value of the variable the reference refers to.

Just like make Anglerfish attached to a female Anglerfish.

  */
  int x{3};
  int& xRef{x};

  println("x={}", x);
  println("xRef={}", xRef);

  x = 4;
  println("change x to 4");
  println("x={}", x);
  println("xRef={}", xRef);

  xRef = 5;
  println("change xRef to 4");
  println("x={}", x);
  println("xRef={}", xRef);

  int z{2};
  const int& zRef{z};
  // zRef = 4; //DOES NOT COMPILE.
  /*
  > g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
reference.cpp
./reference.cpp: In function 'int main()':
./reference.cpp:44:8: error: assignment of read-only reference 'zRef'
   44 |   zRef = 4;
      |   ~~~~~^~~

  */

  println("z={}", z);
  println("zRef={}", zRef);

  z = 3;
  println("change z to 3");
  println("z={}", z);
  println("zRef={}", zRef);

  /*
  You cannot create a reference to an unnamed value, such as an integer literal,
  unless the reference is to a const value. In the following example,
  unnamedRef1 does not compile because it is a referenceto- non-const referring
  to a constant. That would mean you could change the value of the constant, C++
  Crash Course ❘ 61 5, which doesn’t make sense. unnamedRef2 works because it’s
  a reference-to-const, so you cannot for example write unnamedRef2 = 7.
  */

  // int& unnamedRef1{5};  // DOES NOT COMPILE
  /*
  > g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
  reference.cpp
  ./reference.cpp: In function 'int main()':
  ./reference.cpp:62:21: error: cannot bind non-const lvalue reference of type
  'int&' to an rvalue of type 'int' 62 |   int& unnamedRef1{5};        // DOES
  NOT COMPILE |                     ^

  */

  const int& unnamedRef2{5};  // Works as expected

  /*
  The same holds for temporary objects. You cannot create a
  reference-to-non-const to a temporary object, but a reference-to-const is
  fine.
  */

  // string& string1 { getString() }; // DOES NOT COMPILE

  /*
  > g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello
  reference.cpp
  ./reference.cpp: In function 'int main()':
  ./reference.cpp:84:31: error: cannot bind non-const lvalue reference of type
  'std::string&' {aka 'std::__cxx11::basic_string<char>&'} to an rvalue of type
  'std::string' {aka 'std::__cxx11::basic_string<char>'} 84 | string& string1 {
  getString() }; // DOES NOT COMPILE |                               ^

  */

  const string& string2{getString()};  // Works as expected

  ptrRef1();
  ptrRef2();

  int jint {15};
  int & jRef {jint};
  
  MyClass my(jRef);
  my.PrintRef();

  int xx {5},  yy{6};
  println("x={}, y={}", xx, yy);

  swap (xx,yy);
  println("x={}, y={}", xx, yy);

  string someString { "Hello World" };
printString(someString);
printString("Hello World again"); // Passing literals works.

vector<int> vecUnSplit { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
vector<int> odds, evens;
seperateOddsAndEvens(vecUnSplit, odds, evens);

println("odds={}", odds);
println("evens={}",evens);



vector<int> vecUnSplit2 { 11, 12, 13, 14, 15, 16, 17, 18, 19, 110 };

OddsAndEvens myOandE {seperateOddsAndEvens(vecUnSplit2)};

println("myOandE.odds={}", myOandE.odds);

println("myOandE.evens={}", myOandE.evens);
}