#include <iostream>

struct MyStruct {
    void Function() {
        std::cout << "counter: " << counter << std::endl;

        auto f = [*this]() mutable{
            counter ++;

            return counter; };

        std::cout << "ii: " << f() << std::endl;

    };

    int counter {0};
};

int main() {

    MyStruct instance;

    instance.Function();
    instance.Function();
    instance.Function();
    instance.Function();



    return 0;
}
