module spreadsheet_cell;

import std;
using namespace std;

void SpreadsheetCell::setValue(double value) { m_value = value; }

double SpreadsheetCell::getValue() const { return m_value; }

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
