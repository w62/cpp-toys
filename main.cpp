//#include <iostream>

#include <iostream>
struct Foo
{
    int x{};
    int y{};

public:
    Foo()
    {
        x = 5;
    }

    Foo(int value):  Foo()
    {
        // intent: call Foo() function
        // actual: value initializes nameless temporary Foo (which is then discarded)
//        Foo(); // note: this is the equivalent of writing Foo{}
//
        y = value;
    }
};

int main()
{
    Foo f{ 9 };
    std::cout << f.x << ' ' << f.y; // prints 0 9
}
