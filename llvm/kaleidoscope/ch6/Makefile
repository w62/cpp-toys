CXX=clang++
CXXFLAGS = -g `llvm-config --cxxflags --ldflags --system-libs --libs core orcjit native` -O3

PRG=ch6
TPRG=t

$(PRG): $(PRG).cpp
	$(CXX) $(CXXFLAGS) -o $(PRG) $(PRG).cpp

$(TPRG): $(TPRG).cpp
	$(CXX) $(CXXFLAGS) -o $(TPRG) $(TPRG).cpp

all: $(PRG) $(TPRG)
