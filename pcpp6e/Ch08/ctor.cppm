export module ctor;
import std;
class Foo {
 public:
  Foo(double value);

 private:
  double m_value{0};
};

export class MyClass {
 public:
  MyClass(double value);

 private:
  // There is one important caveat with ctor-initializers:
  // they initialize data members in the order that they
  // appear in the class definition, not their order in the ctor-initializer!

  double m_value{0};  // this is initialized first
  Foo m_foo;          // this is initialized second
};

// Order is significant. Parent must appear before child