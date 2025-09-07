CXX=g++-15
CXX_STANDARD=-std=c++23
MODULE_FLAGS=-fmodules-ts -fsearch-include-path bits/std.cc
CXX_FLAGS=-c -x c++

# g++-15 -std=c++23 -fmodules-ts  -o EmployeeTest EmployeeTest.cpp Employee.cpp std.o Employee.o

STRING03=03_cpp_string

all: $(STRING03)

$(STRING03): $(STRING03).cpp 	
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(STRING03) $(STRING03).cpp 
	
ifeq ("x","y")
$(EMPLOYEE).o: $(EMPLOYEE).cppm $(EMPLOYEE).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(EMPLOYEE).cppm

$(EMPLOYEE_TEST): $(EMPLOYEE)Test.cpp $(EMPLOYEE).cppm $(EMPLOYEE).cpp $(EMPLOYEE).o
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(EMPLOYEE_TEST) $(EMPLOYEE_TEST).cpp  $(EMPLOYEE).cpp $(EMPLOYEE).o 

$(DATABASE).o: $(DATABASE).cppm $(DATABASE).cpp $(EMPLOYEE).o
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(DATABASE).cppm

$(DATABASE_TEST): $(DATABASE)Test.cpp $(DATABASE).cppm $(DATABASE).cpp $(EMPLOYEE).o 
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(DATABASE_TEST) $(DATABASE_TEST).cpp  $(DATABASE).cpp $(DATABASE).o $(EMPLOYEE).cpp  $(EMPLOYEE).o 


$(USERINTERFACE): $(USERINTERFACE).cpp $(EMPLOYEE).o $(DATABASE).o $(EMPLOYEE).cpp $(DATABASE).cpp	
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(USERINTERFACE) $(USERINTERFACE).cpp $(EMPLOYEE).o $(DATABASE).o $(EMPLOYEE).cpp $(DATABASE).cpp

clean:
	rm *.o
	rm -fr gcm.cache
	rm $(EMPLOYEE_TEST)
	rm $(DATABASE_TEST)
	rm $(USERINTERFACE)
endif