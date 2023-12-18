failed with the following message:

```
> make
clang++ -g `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -O3 -o ch8 ch8.cpp
ch8.cpp:1317:36: error: no member named 'ObjectFile' in 'llvm::CodeGenFileType'
 1317 |   auto FileType = CodeGenFileType::ObjectFile;
      |                   ~~~~~~~~~~~~~~~~~^
1 error generated.
make: *** [Makefile:8: ch8] Error 1
```

```
> clang++ --version
Homebrew clang version 17.0.6
Target: arm64-apple-darwin23.2.0
Thread model: posix
InstalledDir: /opt/homebrew/opt/llvm/bin
```

```
> sw_vers
ProductName:		macOS
ProductVersion:		14.2
BuildVersion:		23C64
```
