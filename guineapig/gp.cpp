#include <iostream>
#include <typeinfo>

/*
 * https://www.youtube.com/watch?v=irFkMavpL9A&list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L&index=75
 */

template<typename T>
T Sum (T arg) {
    return arg;
}

template<typename T, typename...Args>
T Sum(T start, Args...args) {
    return start + Sum(args...);
}

int main() {

    std::cout << Sum(1,2,3,4,5) << std::endl;
    std::cout << std::endl;
    std::cout << Sum(3,4,5) << std::endl;
    return 0;
}
