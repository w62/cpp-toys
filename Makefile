# my make file
# based on here: https://www.softwaretestinghelp.com/cpp-makefile-tutorial/
CXX=g++-13
RM=rm

MFLAGS=-fmodules-ts 
HFLAGS=-x c++-system-header
CFLAGS=-std=c++20 -ggdb -pedantic-errors -Wall -Weffc++ \
	   -Wextra -Wconversion -Wsign-conversion -Werror

MODULES = iostream
GCM_CACHE = gcm.cache

MAIN = main
HELLOWORLD = helloworld
TARGETS = $(MAIN) $(HELLOWORLD)


all: $(TARGETS)

force:
	for i in $(TARGETS); do \
		($(CXX) $(CFLAGS) $(MFLAGS) $(HFLAGS) $(MODULES) && \
		$(CXX) $(CFLAGS) $(MFLAGS) -o $$i $$i.cpp) || exit1; \
	done

$(MAIN): $(MAIN).cpp
	$(CXX) $(CFLAGS) $(MFLAGS) $(HFLAGS) $(MODULES)
	$(CXX) $(CFLAGS) $(MFLAGS) -o $(MAIN) $(MAIN).cpp
	./$(MAIN)

$(HELLOWORLD): $(HELLOWORLD).cpp
	$(CXX) $(CFLAGS) $(MFLAGS) $(HFLAGS) $(MODULES)
	$(CXX) $(CFLAGS) $(MFLAGS) -o $(HELLOWORLD) $(HELLOWORLD).cpp
	./$(HELLOWORLD)

clean:
	for i in $(TARGETS); do \
		$(RM) $$i || exit 1; \
	done
	$(RM) -fr $(GCM_CACHE)
