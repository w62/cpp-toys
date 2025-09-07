import std;
using namespace std;

int main() {
  string a{"34"};
  string b{"12"};
  string c{a + b};  // operator overload. More on this later.

  string dd{"Hello"};
  string e{"World"};

  println("\"{}\" < \"{}\" = \"{}\" ", dd, e, dd < e);
  println("\"{}\" > \"{}\" = \"{}\" ", dd, e, dd > e);

  auto result{a <=> b};
  if (is_gt(result)) {
    println("greater");
  }
  if (is_lt(result)) {
    println("less");
  }
  if (is_eq(result)) {
    println("equal");
  }

  string myString{"hello"};
  myString += ", there";
  string myOtherString{myString};
  if (myString == myOtherString) {
    myOtherString[0] = 'H';
  }
  println("{}", myString);
  println("{}", myOtherString);

  /*
  There are several things to note in this example. One point is that there are
no memory leaks even though strings are allocated and resized in a few places.
All of these string objects are created as stack variables. While the string
class certainly has a bunch of allocating and resizing to do, the string
destructors clean up this memory when string objects go out of scope. How
exactly destructors work is explained in detail in Chapter 8, “Gaining
Proficiency with Classes and Objects.” Another point to note is that the
operators work the way you want them to work. For example, the = operator copies
the strings, which is most likely what you want. If you are used to working with
array-based
strings, this will be either refreshingly liberating for you or somewhat
confusing. Don’t worry—once you learn to trust the string class to do the right
thing, life gets so much easier.
  */

  string strHello{"Hello!!"};
  string strWorld{"The World..."};

  auto position{strHello.find("!!")};
  if (position != string::npos) {
    strHello.replace(position, 2, strWorld.substr(3, 6));
  }

  println("{}", strHello);
  string toFind{"World"};
  println("{}", strWorld.contains(toFind));
  println("{}", strWorld.contains("Hello"));  // contains(str)/contains(ch):
  println("{}", strWorld.contains('.'));  // Returns true if a string contains
                                          // another string or character
  /*
  Before C++23, it was possible to construct a string object by passing nullptr
  to its constructor. This would then result in undefined behavior at run time.
  Starting with C++23, trying to construct a string from nullptr results in a
  compilation error.
  */

  auto string1{"Hello World"};   // string1 is a const char*.
  auto& string2{"Hello World"};  // string2 is a const char[12].
  auto string3{"Hello World"s};  // string3 is an std::string.
  /*
  CTAD with std::vector and Strings
  Chapter 1 explains that std::vector supports class template argument deduction
  (CTAD), allowing the compiler to automatically deduce the type of a vector
  based on an initializer list. You have to be careful when using CTAD for a
  vector of strings. Take the following declaration of a vector, for example: */

  vector names{"John", "Sam", "Joe"};

  /*
  The deduced type will be vector<const char*>, not vector<string>! This is an
  easy mistake to make and can lead to some strange behavior of your code, or
  even crashes, depending on what you do with the vector afterward. If you want
  a vector<string>, then use std::string literals as explained in the previous
  section. Note the s behind each string literal in the following example:
  */

  vector names2{"John"s, "Sam"s, "Joe"s};

  const string toParse{" 123USD"};
  size_t index{0};
  int value{stoi(toParse, &index)};
  println("Parsed value: {}", value);
  println("First non-parsed character: '{}'", toParse[index]);

  /*
A string_view should not be used to store a view of a temporary string. Take the
following example: */

  string s{"Hello"};
  string_view sv{s + " World!"};
  println("{}", sv);

  /*
  This code snippet has undefined behavior, i.e., what happens when running this
  code depends on your compiler and compiler settings. It might crash, it might
  print “ello World!” (without the letter H), and so on. Why is this undefined
  behavior? The initializer expression for the sv string_view results in a
  temporary string with the “Hello World!” contents. The string_view then stores
  a pointer to this temporary string. At the end of the second line of code,
  this temporary string is destroyed, leaving the string_view with a dangling
  pointer.
  */
  println("こんにちは世界");

  println("😀");
  int n{42};
  println("Read {} bytes from {}", n, "file1.txt");
  println("从{1}中读取{0}个字节。", n, "file1.txt");
  int i{42};
  println("|{:5}|", i);        // | 42|
  println("|{:{}}|", i, 7);    // | 42|
  println("|{1:{0}}|", 7, i);  // | 42|

  println("|{:7}|", i);    // | 42|
  println("|{:<7}|", i);   // |42 |
  println("|{:_>7}|", i);  // |_____42|
  println("|{:_^7}|", i);  // |__42___|

  println("|{:=>16}|", "");  // |================|

  println("|{:<5}|", i);    // |42 |
  println("|{:<+5}|", i);   // |+42 |
  println("|{:< 5}|", i);   // | 42 |
  println("|{:< 5}|", -i);  // |-42 |

  println("|{:10d}|", i);   // | 42|
  println("|{:10b}|", i);   // | 101010|
  println("|{:#10b}|", i);  // | 0b101010|
  println("|{:10X}|", i);   // | 2A|
  println("|{:#10X}|", i);  // | 0X2A|

  s = "ProCpp";
  println("");
  println("|{:_^10}|", s);  // |__ProCpp__|

  double d{3.1415 / 2.3};

  println("|{:12g}|", d);   // | 1.36587|
  println("|{:12.2}|", d);  // | 1.4|
  println("|{:12e}|", d);   // |1.365870e+00|
  int width{12};
  int precision{3};
  println("|{2:{0}.{1}f}|", width, precision, d);  // | 1.366|
  println("|{2:{0}.{1}}|", width, precision, d);   // | 1.37|

  println("|{:06d}|", i);   // |000042|
  println("|{:+06d}|", i);  // |+00042|
  println("|{:06X}|", i);   // |00002A|
  println("|{:#06X}|", i);  // |0X002A|

  println("|{:?}|", "Hello\tWorld!\n");  // |Hello\tWorld!\n|
  println("|{:?}|", "\"");               // |"\""|
  println("|{:?}|", '\'');               // |'\''|
  println("|{:?}|", '"');                // |'"'|

  vector values{11, 22, 33};

  println("{}", values);    // [11, 22, 33]
  println("{:n}", values);  // 11, 22, 33

  println("{{{:n}}}", values);  // {11, 22, 33}

  println("{:*^16}", values);   // **[11, 22, 33]**
  println("{:*^16n}", values);  // ***11, 22, 33***
  println("{::*^6}", values);   // [**11**, **22**, **33**
  println("{:n:*^6}", values);  // **11**, **22**, **33**

  vector strings{"Hello"s, "World!\t2023"s};
  println("{}", strings);     // ["Hello", "World!\t2023"]
  println("{:}", strings);    // ["Hello", "World!\t2023"]
  println("{::}", strings);   // [Hello, World! 2023]
  println("{:n:}", strings);  // Hello, World! 2023

  vector chars{'W', 'o', 'r', 'l', 'd', '\t', '!'};
  println("{}", chars);      // ['W', 'o', 'r', 'l', 'd', '\t', '!']
  println("{::#x}", chars);  // [0x57, 0x6f, 0x72, 0x6c, 0x64, 0x9, 0x21]
  println("{:s}", chars);    // World !
  println("{:?s}", chars);   // "World\t!"

  pair p{11, 22};
  println("{}", p);    // (11, 22)
  println("{:n}", p);  // 11, 22
  println("{:m}", p);  // 11: 22

  vector<vector<int>> vv{{11, 22}, {33, 44, 55}};

  println("{}", vv);          // [[11, 22], [33, 44, 55]]
  println("{:n}", vv);        // [11, 22], [33, 44, 55]
  println("{:n:n}", vv);      // 11, 22, 33, 44, 55
  println("{:n:n:*^4}", vv);  // *11*, *22*, *33*, *44*, *55*
}