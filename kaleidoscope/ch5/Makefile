CXX=clang++
CXXFLAGS = -g `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -O3

PRG=ch5

$(PRG): $(PRG).cpp
	$(CXX) $(CXXFLAGS) -o $(PRG) $(PRG).cpp
