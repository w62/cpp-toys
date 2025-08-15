#include <iomanip>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

int main()
{
        std::string line;
        std::getline(std::cin, line);
        std::istringstream iss{line};
        std::getline(iss >> std::ws, line);
        std::cout << "ws + getline returns:\t" << std::quoted(line) << '\n';
        remove(line.begin(), line.end(), ' ');
        std::cout << "after remove returns:\t" << std::quoted(line) << '\n';
        /*
    for (const char* str : {"     #1 test", "\t #2 test", "#3 test"})
    {
        std::string line;
        std::getline(std::istringstream{str}, line);
        std::cout << "getline returns:\t" << std::quoted(line) << '\n';

        std::istringstream iss{str};
        std::getline(iss >> std::ws, line);
        std::cout << "ws + getline returns:\t" << std::quoted(line) << '\n';
    } */
        return 0;
}

