update original Ch00/AirlineTicket to use import std;

g++-15 -std=c++23 -fmodules-ts -xc++-system-header string
g++-15 -std=c++23 -fmodules-ts -c -x c++ AirlineTicket.cppm
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc -o hello AirlineTicket.cpp AirlineTicketTest.cpp AirlineTicket.o
./hello
hello
This ticket will cost $70
This ticket will cost $70
