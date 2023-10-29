#pragma once
#include <cstddef>

#include "SpreadsheetCell.h"

class SpreadsheetApplication; // forward declaration

class Spreadsheet {
 public:

  Spreadsheet( size_t width, size_t height,
          const SpreadsheetApplication& theApp);

  Spreadsheet(const Spreadsheet& src);
  ~Spreadsheet();
  Spreadsheet& operator=(const Spreadsheet& rhs);

  void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
  const SpreadsheetCell& getCellAt(size_t x, size_t y) const;

  size_t getId() const;

  friend void swap (Spreadsheet& first, Spreadsheet& second) noexcept;

  static const size_t kMaxHeight = 100;
  static const size_t kMaxWidth = 100;

 private:
  void verifyCoordinate(size_t x, size_t y) const;

  void cleanup() noexcept;
  void moveFrom(Spreadsheet& src) noexcept;
  bool inRange(size_t value, size_t upper) const;

  size_t mId = 0;
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
  const SpreadsheetApplication& mTheApp;

  static size_t sCounter;

};
