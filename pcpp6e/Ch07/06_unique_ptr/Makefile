CXX=g++-15
CXX_STANDARD=-std=c++23
MODULE_FLAGS=-fmodules-ts -fsearch-include-path bits/std.cc
CXX_FLAGS=-c -x c++

# g++-15 -std=c++23 -fmodules-ts  -o EmployeeTest EmployeeTest.cpp Employee.cpp std.o Employee.o

TARGET=unique

all: $(TARGET)

$(TARGET): $(TARGET).cpp 	
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(TARGET) $(TARGET).cpp 



clean:
	- rm *.o
	- rm -fr gcm.cache
	- rm $(TARGET)
