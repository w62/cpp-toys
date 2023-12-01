/*
 * This is the initial test program from
 * https://layle.me/posts/using-llvm-with-cmake/
 * The purpose is to verify if LLVM can be embedded into a project.
 *
 */
#include <iostream>
#include <llvm/IR/Module.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/IRBuilder.h>

#include <vector>
#include <memory>

using llvm::LLVMContext;
using llvm::IRBuilder;
using llvm::Module;
using llvm::FunctionType;
using llvm::Function;
using llvm::BasicBlock;
using llvm::Type;
using llvm::ArrayRef;

int main(int argc, char* argv[])
{
    std::cout << "hello world! BB" << std::endl;
    return 0;
}

