cmake_minimum_required(VERSION 3.12)
project(toy)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER  clang++)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG -march=native)
set(CMAKE_CXX_FLAGS_RELEASE -march=native)
find_package(LLVM REQUIRED CONFIG)

set(LLVM_LINK_COMPONENTS
  Analysis
  Core
  ExecutionEngine
  InstCombine
  Object
  OrcJIT
  Passes
  RuntimeDyld
  ScalarOpts
  Support
  native
  )

message(STATUS "Wow! Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "OK, Using LLVMConfig.cmake in: ${LLVM_DIR}")
include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})
#add_executable(toy toy.cpp)
#add_executable(his_toy his_toy.cpp)


# ld: warning: ignoring duplicate libraries: '/opt/homebrew/opt/llvm/lib/libLLVMCore.a', '/opt/homebrew/opt/llvm/lib/libLLVMSupport.a'
llvm_map_components_to_libnames(llvm_libs support orcjit native core irreader)
# so changed to use irreader only

#llvm_map_components_to_libnames(llvm_libs irreader)

#target_link_libraries(toy ${llvm_libs})
#target_link_libraries(his_toy ${llvm_libs})
#message(STATUS "will link toy with ${llvm_libs}")

# This file is based on the example from
# https://llvm.org/docs/CMake.html#id19
# in the LLVM homepage
