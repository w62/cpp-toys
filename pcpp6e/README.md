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


 --style=<string>               - Set coding style. <string> can be:
                                   1. A preset: LLVM, GNU, Google, Chromium, Microsoft,
                                      Mozilla, WebKit.
                                   2. 'file' to load style configuration from a
                                      .clang-format file in one of the parent directories
                                      of the source file (for stdin, see --assume-filename).
                                      If no .clang-format file is found, falls back to
                                      --fallback-style.
                                      --style=file is the default.
                                   3. 'file:<format_file_path>' to explicitly specify
                                      the configuration file.
                                   4. "{key: value, ...}" to set specific parameters, e.g.:


g++-15 -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc  -c -x c++ -o 



* value ``d0edc3af-4c50-42ea-a356-e2862fe7a444``.