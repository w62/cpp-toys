CXX=g++-15
CXX_STANDARD=-std=c++23
MODULE_FLAGS=-fmodules-ts -fsearch-include-path bits/std.cc
CXX_FLAGS=-c -x c++ 

# g++-15 -std=c++23 -fmodules-ts  -o EmployeeTest EmployeeTest.cpp Employee.cpp std.o Employee.o

TARGET1=Friends

TARGET2=SpreadsheetCell
TARGET3=Spreadsheet
TARGET4=Target4

MASTERTEST=MasterTest

all: $(MASTERTEST) $(MASTERTEST).cpp $(TARGET1).o $(TARGET2).o $(TARGET3).o $(TARGET4).o

$(TARGET1).o: $(TARGET1).cppm $(TARGET1).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(TARGET1).cppm

$(TARGET2).o: $(TARGET2).cppm $(TARGET2).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(TARGET2).cppm

$(TARGET3).o: $(TARGET3).cppm $(TARGET3).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(TARGET3).cppm

$(TARGET4).o: $(TARGET4).cppm $(TARGET4).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(TARGET4).cppm


$(MASTERTEST): $(MASTERTEST).cpp $(TARGET1).o  $(TARGET1).cpp $(TARGET2).o $(TARGET2).cpp $(TARGET3).o $(TARGET3).cpp $(TARGET4).o $(TARGET4).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(MASTERTEST) $(MASTERTEST).cpp \
	$(TARGET1).cpp $(TARGET1).o $(TARGET2).o $(TARGET2).cpp $(TARGET3).cpp $(TARGET3).o $(TARGET4).cpp $(TARGET4).o

clean:
	- rm *.o
	- rm -fr gcm.cache
	- rm $(MASTERTEST)
	
