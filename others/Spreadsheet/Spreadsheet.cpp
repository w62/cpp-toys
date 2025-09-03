#include <iostream>
#include <algorithm>
#include "Spreadsheet.h"

size_t Spreadsheet::sCounter;
Spreadsheet::Spreadsheet(size_t width, size_t height,
        const SpreadsheetApplication& theApp)
    : mId(sCounter++)
      , mWidth(std::min(width, kMaxWidth))
      , mHeight(std::min(height, kMaxHeight))
      , mTheApp(theApp)
{
  std::cout << "Normal Constructor" << std::endl;
  std::cout << mId << std::endl;
  mCells = new SpreadsheetCell*[mWidth];
  for (size_t i = 0; i < mWidth; i++) {
    mCells[i] = new SpreadsheetCell[mHeight];
  }
}


Spreadsheet::Spreadsheet(const Spreadsheet& src)
    : Spreadsheet(src.mWidth, src.mHeight, src.mTheApp) {
  std::cout << "Copy Constructor" << std::endl;
  for (size_t i = 0; i < mWidth; i++) {
    for (size_t j = 0; j < mHeight; j++) {
      mCells[i][j] = src.mCells[i][j];
    }
  }
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {

  std::cout << "Copy Assignment operator" << std::endl;
  // Check for self-assignment
  if (this == &rhs) {
    return *this;
  }

  Spreadsheet temp(rhs);  // Do all the work in a temporary instance
  swap(*this, temp);      // Commit the work with only non-throwing operations
  return *this;
}



void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell) {
  verifyCoordinate(x, y);
  mCells[x][y] = cell;
}


const SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y) const {
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

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const {
  if (x >= mWidth || y >= mHeight) {
    throw std::out_of_range("");
  }
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
    std::swap(first.mWidth, second.mWidth);
    std::swap(first.mHeight, second.mHeight);
    std::swap(first.mCells, second.mCells);
}
