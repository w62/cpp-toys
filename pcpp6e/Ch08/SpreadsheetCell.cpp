module spreadsheet_cell;

import std;
using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) {
  setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue) {
  setString(initialValue);
}

/* Copy constructors for the sake of demo
SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
    : m_value{src.m_value} {}
*/
void SpreadsheetCell::setValue(double value) { m_value = value; }

void SpreadsheetCell::setValue2(double value) {
  this->value = value;
  printCell(*this);
}

void SpreadsheetCell::setValue223(this SpreadsheetCell& self, double value) {
  self.value = value;
  println("setValue23: Begin");
  printCell(self);
  println("self.getValue(): {}", self.getValue());
  println("self.getValue2(): {}", self.getValue2());
  println("self.getString(): {}",
          self.getString());  // call this object's member function
  println("self.value: {}",
          self.value);  // access this object's private data member
  println("setValue23: End");
}

double SpreadsheetCell::getValue() const { return m_value; }

double SpreadsheetCell::getValue2() const { return value; }

void SpreadsheetCell::setString(string_view value) {
  m_value = stringToDouble(value);
}

string SpreadsheetCell::getString() const {
  return doubleToString(m_value);
  //        return SpreadsheetCell::doubleToString(m_value); this one works as
  //        well
}
// 👆🏿 this function calls 👇 this function within the same class
string SpreadsheetCell::doubleToString(double value) const {
  return to_string(value);
}

double SpreadsheetCell::stringToDouble(string_view value) const {
  double number{0};
  from_chars(value.data(), value.data() + value.size(), number);
  return number;
}

// You can call member functions of a class from inside another member function.

void printCell(const SpreadsheetCell& cell) {
  println("===");
  println("printCell: {}", cell.getValue2());
  println("===");
}
