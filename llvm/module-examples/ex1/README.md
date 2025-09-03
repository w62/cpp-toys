
[based on here](https://clang.llvm.org/docs/StandardCPlusPlusModules.html)
```
clang++ -std=c++23 src/Hello.cppm --precompile -o build/Hello.pcm
clang++ -std=c++23 src/use.cpp -fmodule-file=Hello=build/Hello.pcm build/Hello.pcm -o build/Hello.out
build/Hello.out
```

```
00:14 星期Wed 03-Sep-2025 HKT
/Users/william/projects/cpp-toys/llvm/module-examples/ex1
> g++-15 -std=c++23 -fmodules-ts -c -x c++ src/Hello.cppm -o mybuild/Hello.o

william@Mac
00:15 星期Wed 03-Sep-2025 HKT
/Users/william/projects/cpp-toys/llvm/module-examples/ex1
> g++-15 -std=c++23 -fmodules-ts -o mybuild/use src/use.cpp mybuild/Hello.o

william@Mac
00:15 星期Wed 03-Sep-2025 HKT
/Users/william/projects/cpp-toys/llvm/module-examples/ex1
> mybuild/use
Hello World!
```

TODO
- create a Makefile or a Cmake project 