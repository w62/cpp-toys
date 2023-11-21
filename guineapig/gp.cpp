#include <iostream>
#include <typeinfo>

int main() {

    int x;
    int& ref = x;

    struct myStruct {
        double d;
        bool b;
    } mStruct;

    myStruct& t = mStruct;


    std::cout << "x type: " << typeid(x).name() << std::endl;
    std::cout << "ref type: " << typeid(ref).name() << std::endl;

    std::cout << "mStruct type: " << typeid(mStruct).name() << std::endl;
    std::cout << "t type: " << typeid(t).name() << std::endl;

  return (0);
}
