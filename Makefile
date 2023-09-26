# my make file
# based on here: https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
CXX=clang++-16
RM=rm

# clang++ -std=c++20 -xc++-system-header --precompile iostream -o iostream.pcm
# clang++ -std=c++20 -fmodule-file=iostream.pcm -o helloworld helloworld.cpp


CSTANDARD=-std=c++20

CFLAGS=-ggdb -pedantic-errors -Wall -Weffc++ \
	   -Wextra -Wconversion -Wsign-conversion -fuse-ld=lld -stdlib=libc++

MFLAGS = -xc++-system-header --precompile 
HFLAGS = -fmodule-file=$(MODULES).pcm

MODULES = iostream
GCM_CACHE = gcm.cache

MAIN = main
HELLOWORLD = helloworld
ADD = add

TARGETS = $(MAIN) $(HELLOWORLD)


all: $(TARGETS)


$(MAIN): $(MAIN).cpp
	$(CXX) $(CSTANDARD) $(MFLAGS) $(MODULES) -o $(MODULES).pcm
	$(CXX) $(CSTANDARD) $(CFLAGS) $(HFLAGS)  -o $(MAIN) $(MAIN).cpp $(ADD).cpp
	./$(MAIN)	



$(HELLOWORLD): $(HELLOWORLD).cpp
	$(CXX) $(CFLAGS) -o $(HELLOWORLD) $(HELLOWORLD).cpp
	./$(HELLOWORLD)	

clean:
	for i in $(TARGETS); do \
		$(RM) $$i || exit 1; \
	done
	$(RM) -fr $(GCM_CACHE)
