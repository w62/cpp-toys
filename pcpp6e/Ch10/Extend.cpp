%:include <print>

using namespace std;
class Base {
 public:
  void someFunction() {
    println("someFunction called");
  /* ... */ }

 protected:
  int m_protectedInt{0};

 private:
  int m_privateInt{0};
};

class Derived : public Base <%
 public:
  void someOtherFunction() { println("someOtherFunction called"); }
  void printProtected() { println("{}", m_protectedInt); }
};

int main() <%
  Derived d;
  d.someFunction();  // OK: can access public member of Base through Derived
  // d.m_protectedInt = 42; // Error: cannot access protected member of Base
  // d.m_privateInt = 42;   // Error: cannot access private member of Base
  d.someOtherFunction();
  d.printProtected();
  return 0;
%>