#pragma once
#include <cstddef>

#include "SpreadsheetCell.h"

class Spreadsheet {
 public:
  Spreadsheet(size_t width, size_t height);
  Spreadsheet(const Spreadsheet& src);
  Spreadsheet& operator=(const Spreadsheet& rhs);

  Spreadsheet(Spreadsheet&& src) noexcept;
  Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;

  friend void swap (Spreadsheet& first, Spreadsheet& second) noexcept;
  void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
  SpreadsheetCell& getCellAt(size_t x, size_t y);
  ~Spreadsheet();

 private:
  Spreadsheet() = default;
  void cleanup() noexcept;
  void moveFrom(Spreadsheet& src) noexcept;
  bool inRange(size_t value, size_t upper) const;
  void verifyCoordinate(size_t x, size_t y) const;
  size_t mWidth = 0;
  size_t mHeight = 0;

  SpreadsheetCell** mCells = nullptr;
  /*
  Note that the Spreadsheet class does not contain a standard two-dimensional
array of SpreadsheetCells. Instead, it contains a SpreadsheetCell**. This is
because each Spreadsheet object might have different dimensions, so the
constructor of the class must dynamically allocate the two-dimensional array
based on the client-specified height and width.
*/
};
