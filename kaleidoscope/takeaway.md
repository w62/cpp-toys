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
