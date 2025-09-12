CXX=g++-15
CXX_STANDARD=-std=c++23
MODULE_FLAGS=-fmodules-ts -fsearch-include-path bits/std.cc
CXX_FLAGS=-c -x c++

# g++-15 -std=c++23 -fmodules-ts  -o EmployeeTest EmployeeTest.cpp Employee.cpp std.o Employee.o

SPREADSHEETCELL=SpreadsheetCell

CTOR=ctor
TARGET3=initializer_list

SPREADSHEETCELLTEST=$(SPREADSHEETCELL)Test

all: $(SPREADSHEETCELLTEST) $(SPREADSHEETCELL).o  $(SPREADSHEETCELLTEST).cpp $(CTOR).cpp $(TARGET3).cpp $(TARGET3).o

$(TARGET3).o: $(TARGET3).cppm $(TARGET3).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(TARGET3).cppm

$(CTOR).o: $(CTOR).cppm $(CTOR).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(CTOR).cppm

$(SPREADSHEETCELL).o: $(SPREADSHEETCELL).cppm $(SPREADSHEETCELL).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS) $(CXX_FLAGS) $(SPREADSHEETCELL).cppm

$(SPREADSHEETCELLTEST): $(SPREADSHEETCELLTEST).cpp $(SPREADSHEETCELL).o  $(SPREADSHEETCELL).cpp $(CTOR).o $(CTOR).cpp $(TARGET3).o $(TARGET3).cpp
	$(CXX) $(CXX_STANDARD) $(MODULE_FLAGS)  -o $(SPREADSHEETCELLTEST) $(SPREADSHEETCELLTEST).cpp \
	$(SPREADSHEETCELL).cpp $(SPREADSHEETCELL).o $(CTOR).o $(CTOR).cpp $(TARGET3).cpp $(TARGET3).o

clean:
	- rm *.o
	- rm -fr gcm.cache
	- rm $(SPREADSHEETCELLTEST)
	
