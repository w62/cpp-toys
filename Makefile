# my make file
# based on here: https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
CXX=clang++
RM=rm

# clang++ -std=c++20 -xc++-system-header --precompile iostream -o iostream.pcm
# clang++ -std=c++20 -fmodule-file=iostream.pcm -o helloworld helloworld.cpp

# MFLAGS=-fmodules-ts 
# HFLAGS=-x c++-system-header
#CFLAGS=-std=c++20 -ggdb -pedantic-errors -Wall -Weffc++ \
	   -Wextra -Wconversion -Wsign-conversion -Werror

MFLAGS = -xc++-system-header --precompile 
HFLAGS = -fmodule-file
CFLAGS = -std=c++20 

MODULES = iostream
GCM_CACHE = gcm.cache

MAIN = main
HELLOWORLD = helloworld
TARGETS = $(MAIN) $(HELLOWORLD)


all: $(TARGETS)

# gcc version
#$(MAIN): $(MAIN).cpp
#	$(CXX) $(CFLAGS) $(MFLAGS) $(HFLAGS) $(MODULES)
#	$(CXX) $(CFLAGS) $(MFLAGS)-o $(MAIN) $(MAIN).cpp
#	./$(MAIN)

$(MAIN): $(MAIN).cpp
	$(CXX) $(CFLAGS) $(MFLAGS) $(MODULES) -o $(MODULES).pcm 
	$(CXX) $(CFLAGS) $(HFLAGS)=$(MODULES).pcm -o $(MAIN) $(MAIN).cpp
	./$(MAIN)	


#gcc version
#$(HELLOWORLD): $(HELLOWORLD).cpp
#	$(CXX) $(CFLAGS) $(MFLAGS) $(HFLAGS) $(MODULES)
#	$(CXX) $(CFLAGS) $(MFLAGS) -o $(HELLOWORLD) $(HELLOWORLD).cpp
#	./$(HELLOWORLD)

$(HELLOWORLD): $(HELLOWORLD).cpp
	$(CXX) $(CFLAGS) $(MFLAGS) $(MODULES) -o $(MODULES).pcm 
	$(CXX) $(CFLAGS) $(HFLAGS)=$(MODULES).pcm -o $(HELLOWORLD) $(HELLOWORLD).cpp
	./$(HELLOWORLD)	
clean:
	for i in $(TARGETS); do \
		$(RM) $$i || exit 1; \
	done
	$(RM) -fr $(GCM_CACHE)
