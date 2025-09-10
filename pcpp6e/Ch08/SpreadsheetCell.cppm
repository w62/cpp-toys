export module spreadsheet_cell;
import std;
export class SpreadsheetCell {
 public:
  SpreadsheetCell() = default;
  SpreadsheetCell(double initialValue);
  SpreadsheetCell(std::string_view initialValue);
  // SpreadsheetCell(const SpreadsheetCell& src); // Copy constructors for the
  // sake of demo
  void setValue(double);
  void setValue2(double);
  void setValue223(this SpreadsheetCell& self, double value);
  double getValue() const;
  double getValue2() const;

  void setString(std::string_view value);
  std::string getString() const;

 private:
  std::string doubleToString(double value) const;
  double stringToDouble(std::string_view value) const;
  double m_value{0};

  double value{12};
};

void printCell(const SpreadsheetCell& cell);
