#include "SpreadsheetCell.h"
using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue) : mValue(initialValue) {
  // setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue) {
  set(initialValue);
}

void SpreadsheetCell::set(double inValue) { mValue = inValue; }

double SpreadsheetCell::getValue() const {
  mNumAccesses++;
  return mValue;
}

void SpreadsheetCell::set(string_view inString) {
  mValue = stringToDouble(inString);
}

string SpreadsheetCell::getString() const {
  mNumAccesses++;
  return doubleToString(mValue);
}

std::string SpreadsheetCell::doubleToString(double inValue) {
  return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(string_view inString) {
  return strtod(inString.data(), nullptr);
}
