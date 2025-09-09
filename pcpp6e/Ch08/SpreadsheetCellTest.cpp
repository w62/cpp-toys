import std;
import spreadsheet_cell;
using namespace std;
int main() {
  SpreadsheetCell mySC{15};

  println("mySC.getValue()={}", mySC.getValue());
  mySC.setValue(3.0);
  println("now mySC.getValue()={}", mySC.getValue());

  mySC.setString("4.024");
  println("mySC.setString(\" 4.024 \");");
  println("now mySC.getValue()={}", mySC.getValue());
  println("now mySC.getString()={}", mySC.getString());

  SpreadsheetCell myCell{12}, anotherCell{18};
  myCell.setValue(6);
  anotherCell.setString("3.2");
  println("cell 1: {}", myCell.getValue());
  println("cell 2: {}", anotherCell.getValue());

  {
    SpreadsheetCell* myCellp{new SpreadsheetCell{36}};
    myCellp->setValue(3.7);
    println("cell 1: {} {}", myCellp->getValue(), myCellp->getString());
    delete myCellp;
    myCellp = nullptr;
  }

  {
    SpreadsheetCell* myCellp{new SpreadsheetCell{25}};
    (*myCellp).setValue(3.7);
    println("cell 1: {} {}", (*myCellp).getValue(), (*myCellp).getString());
    delete myCellp;
    myCellp = nullptr;
  }

  {
    auto myCellp{make_unique<SpreadsheetCell>(12)};
    myCellp->setValue(3.7);
    println("cell 1: {} {}", myCellp->getValue(), myCellp->getString());
  }

  {
    unique_ptr<SpreadsheetCell> myCellp{new SpreadsheetCell{48}};
    myCellp->setValue(3.7);
    println("cell 1: {} {}", myCellp->getValue(), myCellp->getString());
  }

  /*
  WARNING When you allocate an object with new, free it with delete after you
are finished with it, or, better yet, use smart pointers to manage the memory
automatically!

NOTE If you don’t use smart pointers, it is always a good idea to reset a
pointer to nullptr after deleting the object to which it pointed. You are not
required to do so, but it will make debugging easier in case the pointer is
accidentally used after deleting the object.
  */

  println("mySC.getValue2()={}", mySC.getValue2());
  mySC.setValue2(5.0);
  println("now mySC.getValue2()={}", mySC.getValue2());

  println("mySC.getValue2()={}", mySC.getValue2());
  mySC.setValue223(7.0);
  println("now mySC.getValue2()={}", mySC.getValue2());

  {
    SpreadsheetCell mySC("4.50");
    println("mySC.getString()={}", mySC.getString());
    mySC.setString("32.75");
    println("mySC.getString()={}", mySC.getString());
    SpreadsheetCell aThirdCell{"test"};  // Uses string-arg ctor
    SpreadsheetCell aFourthCell{4.4};    // Uses double-arg ctor
    auto aFifthCellp{make_unique<SpreadsheetCell>("5.5")};  // string-arg ctor
    println("aThirdCell: {}", aThirdCell.getValue());
    println("aFourthCell: {}", aFourthCell.getValue());
    println("aFifthCellp: {}", aFifthCellp->getValue());
  }

  {
    SpreadsheetCell cells[3];
    SpreadsheetCell cell;  // 如果冇  SpreadsheetCell() = default; 爆炸
  }
}