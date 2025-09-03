/*
 *
 https://stackoverflow.com/questions/76154680/how-to-use-module-std-with-gcc
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello 04_input.cpp
 */
import std;
int main()
{
    int value {0};
    std::println("{} + {} = {}", 2, 4, 6);
std::cout << std::format("There are {} ways I love you.", 219) << std::endl;
    std::cin >> value;
    std::println("You entered {}", value);
}
