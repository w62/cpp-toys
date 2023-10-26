#include <iostream>

void handleMessage(std::string& message);
void handleMessage(std::string&& message);

class Foo {
 public:
  Foo(int value) : mData(value) {}
  int mData;
};

std::unique_ptr<Foo> create();

int main() {
  std::string A("hello");

  std::cout << A << std::endl;

  A += ", world again";

  auto mySimpleSmartPtr = std::make_unique<int>();

  // Page 189 Professional C++ 4th ed
  auto foo = std::make_shared<Foo>(42);
  auto aliasing = std::shared_ptr<int>(foo, &foo->mData);
  std::cout << foo->mData << std::endl;
  std::cout << *aliasing << std::endl;

  foo->mData = foo->mData + 1;
  std::cout << "Add 1 to foo->mData" << std::endl;
  std::cout << foo->mData << std::endl;
  std::cout << *aliasing << std::endl;

  auto f2 = create();

  std::cout << f2->mData << std::endl;
  std::string a = "Hello world";
  std::string b = " how are you today";
  handleMessage(a);
  handleMessage("A simple text string");
  std::cout << "call std::move(a)" << std::endl;
  handleMessage(std::move(a));
  /*
   2023-10-25: Page 244, Professional C++ 4th ed.
    You can force the compiler to call the rvalue reference version of
handleMessage() by using std::move(), which casts an lvalue into an rvalue as
follows: handleMessage(std::move(b)); So, inside the handleMessage() function,
the rvalue reference message parameter itself is an lvalue because it has a
name!
   */

  handleMessage(a + b);
  /*
   2023-10-25: Page 244, Professional C++ 4th ed.
  The handleMessage() function accepting an lvalue reference cannot be used,
  because the expression a + b results in a temporary, which is not an lvalue.
  In this case the rvalue reference version is called.
  */
  return 0;
}

std::unique_ptr<Foo> create() {
  auto ptr = std::make_unique<Foo>(15);
  std::cout << "Foo ptr created" << std::endl;
  std::cout << ptr->mData << std::endl;
  return ptr;
}

void handleMessage(std::string& message) {
  std::cout << "handleMessage with lvalue reference: " << message << std::endl;
}
void handleMessage(std::string&& message) {
  std::cout << "handleMessage with rvalue reference: " << message << std::endl;
}
