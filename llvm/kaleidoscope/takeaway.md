for 2. Kaleidoscope: Implementing a Parser and AST,

The AST consists of the following nodes(?):

- NumberAST . e.g. 1.23
- VariableAST . e.g. x
- BinaryAST . e.g. +
- CallAST. e.g. foo()

For functions there are two additional types:

- PrototypeAST. The interface/prototype of the function. e.g. def foo();
- FunctionAST. The definition of the function. e.g. foo() return 0;

The AST is the static data structure whereas the parser is the dynamic mehtods
to construct the AST. 

for 3. Kaleidoscope: Code generation to LLVM IR,

It is relatively easier than 2. The AST classes are updated with IR gen routes.
There are some deviations between the code fragments in the text and the final 
code listing.

my_top.cpp is my own input. his_toy.cpp is the copy-and-paste version from the 
end of the code listing.

for 4. Kaleidoscope: Adding JIT and Optimizer Support, things are bit out of 
control. The CMakeLists.txt somehow does not work. I have to use the compilation
command line in the web page

```
clang++ -g toy.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -O3 -o toy
```

The code are very brief in the web page. The complete code listing at the end
is the program that works. I have copy and paste it into t.cpp and compare the
file with `diff -u3` as well as the result.

Everything is in ch4/ now. I will create a ch5/ in the next step.

For 5. Kaleidoscope: Extending the Language: Control Flow, things are easier 
than expected. It is essentially just dump whatever is there. Code generated
successfully, but we need to wait until later stage.
