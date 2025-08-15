15-aug-2025
===
Quite an overhaul of the directories.
- llvm contains examples from the llvm webpage
- pcpp contains exmaples based on Professional C++
- others are those based on random Internet examples

Just refresh my memories and briefly sort things out. Most things are broken.

15-oct-2023
===
Professinal C++ 4th ed page 186 Customer Deleters using malloc. Updated in 5th ed to use new

09-oct-2023
===
Quite a major update.

1. The testing program helloworld.cpp has been removed.
2. The program of Chapter 1 Professional C++ by Marc Gregorie has been inputed.
3. The project is now build by CMake.


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


19-sep-2023
===
[2.2 - Function return values(value-returning functions)](https://www.learncpp.com/cpp-tutorial/function-return-values-value-returning-functions/)

[2.5 — Introduction to local scope](https://www.learncpp.com/cpp-tutorial/introduction-to-local-scope/)
