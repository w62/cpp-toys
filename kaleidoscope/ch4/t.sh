#!/bin/bash
clang++ -g t.cpp `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -O3 -o t
