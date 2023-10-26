#include <iostream>
#include "Spreadsheet.h"

Spreadsheet::Spreadsheet(size_t width, size_t height)
    : mWidth(width), mHeight(height) {
  mCells = new SpreadsheetCell*[mWidth];
  for (size_t i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }
  std::cout << "Normal Constructor" << std::endl;
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
    : Spreadsheet(src.mWidth, src.mHeight) {
  for (size_t i = 0; i < mWidth; i++) {
    for (size_t j = 0; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
  std::cout << "Move Constructor" << std::endl;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {

  // Check for self-assignment
  if (this == &rhs) {
    return *this;
  }

  Spreadsheet temp(rhs);  // Do all the work in a temporary instance
  swap(*this, temp);      // Commit the work with only non-throwing operations
  return *this;
}

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept {
    swap (*this, src);
}


Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
    Spreadsheet temp(std::move(rhs));
    swap (*this, temp);
    return *this;
}

void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) {
  verifyCoordinate(x, y);
  mCells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) {
  verifyCoordinate(x, y);
  return mCells[x][y];
}

Spreadsheet::~Spreadsheet() 
{
    for (size_t i = 0; i < mWidth; i++) {
        delete[] mCells[i];
    }
    delete[] mCells;
    mCells =nullptr;
    mWidth = mHeight = 0;
}

/*
void Spreadsheet::moveFrom(Spreadsheet& src) noexcept
{
    // Shallow copy of data as they are primitives: Otherwise need to use
    // std::move(src.mWidth)
    mWidth = src.mWidth;
    mHeight = src.mHeight;
    mCells = src.mCells;

    // Reset the source object, because ownership has been moved!
    src.mWidth = 0;
    src.mHeight = 0;
    src.mCells = nullptr;
}
*/
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const {
  if (x >= mWidth || y >= mHeight) {
    throw std::out_of_range("");
  }
}

