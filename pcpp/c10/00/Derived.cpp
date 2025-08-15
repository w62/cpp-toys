#include <iostream>

using namespace std;

class Base {
 public:
  virtual void someMethod();

 protected:
  int mProtectedInt;

 private:
  int mPrivateInt;
};

class Derived : public Base {
 public:
  virtual void someMethod() override;
  virtual void someOtherMethod();
};

int main() {

    Base myBase;
    myBase.someMethod();

    Derived myDerived;
    myDerived.someMethod();

    Base& ref = myDerived;
    myDerived.someOtherMethod();
    ref.someOtherMethod();

  return 0;
}

void Base::someMethod() {
  cout << "This is Base's version of someMethod(). " << endl;
}

void Derived::someMethod() {
  cout << "This is Derived's version of someMethod(). " << endl;
}

void Derived::someOtherMethod() { cout << "SomeOtherMethod " << endl; }
