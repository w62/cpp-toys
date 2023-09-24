# my make file
# based on here: https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
CXX=clang++
RM=rm

# clang++ -std=c++20 -xc++-system-header --precompile iostream -o iostream.pcm
# clang++ -std=c++20 -fmodule-file=iostream.pcm -o helloworld helloworld.cpp

# MFLAGS=-fmodules-ts 
# HFLAGS=-x c++-system-header
CFLAGS=-std=c++20 -ggdb -pedantic-errors -Wall -Weffc++ \
	   -Wextra -Wconversion -Wsign-conversion -Werror

MFLAGS = -xc++-system-header --precompile 
HFLAGS = -fmodule-file

MODULES = iostream
GCM_CACHE = gcm.cache

MAIN = main
HELLOWORLD = helloworld
ADD = add

TARGETS = $(MAIN) $(HELLOWORLD)


all: $(TARGETS)


$(MAIN): $(MAIN).cpp
	$(CXX) $(CFLAGS)  -o $(MAIN) $(MAIN).cpp $(ADD).cpp
	./$(MAIN)	



$(HELLOWORLD): $(HELLOWORLD).cpp
	$(CXX) $(CFLAGS) -o $(HELLOWORLD) $(HELLOWORLD).cpp
	./$(HELLOWORLD)	

clean:
	for i in $(TARGETS); do \
		$(RM) $$i || exit 1; \
	done
	$(RM) -fr $(GCM_CACHE)
