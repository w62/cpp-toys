#include <iostream>
#include <vector>
#include "SpreadsheetCell.h"
#include "Spreadsheet.h"

using namespace std;

Spreadsheet createObject();

int main() {
  // 1. Stack define variables
  SpreadsheetCell myCell(34), anotherCell(32);
  myCell.setValue(6);
  anotherCell.setString("3.2");
  cout << "cell 1: " << myCell.getValue() << endl;
  cout << "cell 2: " << anotherCell.getValue() << endl;

  // 2. Heap traditional C++ pointer - new than delete
  SpreadsheetCell* myCellp = new SpreadsheetCell(56);
  myCellp->setValue(3.7);

  cout << "cell 3: " << myCellp->getValue() << " " << myCellp->getString()
       << endl;

  delete myCellp;
  myCellp = nullptr;

  // 3. Modern C++ smart pointers no need to do memory management
  auto smartCellp = make_unique<SpreadsheetCell>(83);
  //  smartCellp->setValue(4.8);
  cout << "cell 4: " << smartCellp->getValue() << " " << smartCellp->getString()
       << endl;

  SpreadsheetCell aThirdCell("450,000");
  SpreadsheetCell aFourthCell(4.4);
  auto aFifthCellp = make_unique<SpreadsheetCell>(5.5);
  auto aSixthCellp = make_unique<SpreadsheetCell>("test again");

  cout << "aThirdCell: " << aThirdCell.getValue() << endl;
  cout << "aFourthCell: " << aFourthCell.getValue() << endl;
  cout << "aFifthCell: " << aFifthCellp->getValue() << endl;
  cout << "aSixthCell: " << aSixthCellp->getValue() << endl;

  SpreadsheetCell myCell2;
  myCell2.setValue(7);

  cout << "myCell2: " << myCell2.getValue() << endl;
  SpreadsheetCell myCell3(myCell2); // explicitly call the copy constructor
  cout << "myCell3: " << myCell3.getValue() << endl;

  //
  //
  
  auto aSpreadsheet = make_unique<Spreadsheet>(2,3);

  cout << "Spreadsheet: " << aSpreadsheet << endl;

  vector<Spreadsheet> vec;
  for (int i = 0; i < 2; ++i){
      cout<< "Iteration " << i << endl;
      vec.push_back(Spreadsheet(100,100));
      cout << endl;
     }

  Spreadsheet s(2,3);
  s = createObject();

  Spreadsheet s2(5,6);
  s2= s;


  return 0;
}

Spreadsheet createObject() {
    return Spreadsheet(3,2);
}
