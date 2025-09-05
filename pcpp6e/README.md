Very basic compilation flags that support modules, import std; etc.

# support import std;
https://stackoverflow.com/questions/76154680/how-to-use-module-std-with-gcc
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello 01_helloworld.cpp

g++-15 -std=c++23 -fmodules-ts -xc++-system-header iostream
g++-15 -std=c++23 -fmodules-ts -xc++-system-header string


g++-15 -std=c++23 -fmodules-ts -c -x c++ AirlineTicket.cppm


g++-15 -std=c++23 -fmodules-ts -o AirlineTicket AirlineTicket.cpp AirlineTicketTest.cpp AirlineTicket.o

g++-15 -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc  -c -x c++ AirlineTicket.cppm


g++-15 -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc -o AirlineTicket AirlineTicket.cpp AirlineTicketTest.cpp AirlineTicket.o