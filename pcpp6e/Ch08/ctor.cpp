module ctor;

import std;
using namespace std;


Foo::Foo(double value) : m_value{value} {
  println("Foo::m_value = {}", m_value);
}

MyClass::MyClass(double value) : m_value{value}, m_foo{m_value} {
  println("MyClass::m_valeue = {}", m_value);
}


