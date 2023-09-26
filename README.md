19-sep-2023
===
[2.2 - Function return values(value-returning functions)](https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/)

[2.5 — Introduction to local scope](https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/)

24-sep-2023
===

To compile C++20 with gcc
```
g++ -std=c++20 -fmodules-ts -x c++-system-header iostream
g++ -std=c++20 -fmodules-ts -o helloworld helloworld.cpp
./helloworld
Hello, World again!
```

and with clang
```
clang++ -std=c++20 -xc++-system-header --precompile iostream -o iostream.pcm
/usr/lib/gcc/aarch64-linux-gnu/12/../../../../include/c++/12/iostream:36:13: warning: #pragma system_header ignored in main file [-Wpragma-system-header-outside-header]
#pragma GCC system_header
            ^
1 warning generated.

clang++ -std=c++20 -fmodule-file=iostream.pcm -o helloworld helloworld.cpp
```

To use clang-format in vim normal mode:
```
nnoremap <C-K> :%!clang-format <CR>
```
