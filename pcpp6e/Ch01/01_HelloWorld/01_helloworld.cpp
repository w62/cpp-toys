/*
 *

Support for modules was one of the big four new features of C++20, replacing the old mechanism of
header files. If you want to use functionality from a module, you simply import that module. This is
done with an import declaration. Starting with C++23, you can get access to the entire C++ Standard
Library by importing a single standard named module called std. The first line of the “Hello, World”
application imports this standard module:

https://stackoverflow.com/questions/76154680/how-to-use-module-std-with-gcc
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello 01_helloworld.cpp

 *
 */
import std;

int main() {
    std::println("Hello, World!");
    return 0;
}
