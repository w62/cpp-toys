module spreadsheet;

import std;

Spreadsheet::Spreadsheet(std::size_t width, std::size_t height)
    : m_width{width}, m_height{height} {
  m_cells = new SpreadsheetCell*[m_width];
  for (std::size_t i{0}; i < m_width; ++i) {
    m_cells[i] = new SpreadsheetCell[m_height];
  }
}

bool Spreadsheet::inRange(std::size_t value, std::size_t upper) const {
  return value < upper;
}

void Spreadsheet::setCellAt(std::size_t x, std::size_t y,
                            const SpreadsheetCell& cell) {
  verifyCoordinate(x, y);
  m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(std::size_t x, std::size_t y) {
  /*
  Probably this is the reason why google don't use exceptions. We don't when
  will the exception be thrown nor do we know who is going to catch it.
  */

  verifyCoordinate(x, y);
  return m_cells[x][y];
}

void Spreadsheet::verifyCoordinate(std::size_t x, std::size_t y) const {
  if (!inRange(x, m_width)) {
    throw std::out_of_range{
        std::format("x ({}) must be less than width ({}).", x, m_width)};
  }
  if (!inRange(y, m_height)) {
    throw std::out_of_range{
        std::format("y ({}) must be less than height ({}).", y, m_height)};
  }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
    : Spreadsheet{src.m_width, src.m_height} {
  for (std::size_t i{0}; i < m_width; ++i) {
    for (std::size_t j{0}; j < m_height; ++j) m_cells[i][j] = src.m_cells[i][j];
  }
}
Spreadsheet::~Spreadsheet() {
  // Only need to release dynamically allocated memories.
  // No need for primitive types.
  for (std::size_t i{0}; i < m_width; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
  m_cells = nullptr;
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
  std::println("Copy assignment operator");
  // Copy-and-swap idiom
  Spreadsheet temp{rhs};  // Do all the work in a temporary instance
  swap(temp);             // Commit the work with only non-throwing operations
  return *this;
}
Spreadsheet& Spreadsheet::operator=(Spreadsheet&& rhs) noexcept {
  // Check for self-assignment
  if (this == &rhs) {
    return *this;
  }

  swap(rhs);
  ///////
  // 3rd version
  ///
  // Free the old memory and move ownership
  // cleanup();
  // moveFrom(rhs);

  //////////////////////
  // 2nd version
  //////////////////////
  /*
  By default C++'s doing shallow copy. We need to implement deep copy with
  copy-and-swap idiom



*/

  /////////////////
  // 1st version
  /////////////////

  /* // traditional way
  if (this == &rhs) {
    return *this;
  }

  for (std::size_t i{0}; i < m_width; ++i) {
    delete[] m_cells[i];
  }
  delete[] m_cells;
  m_cells = nullptr;

  m_width = rhs.m_width;
  m_height = rhs.m_height;

  m_cells = new SpreadsheetCell*[m_width];
  for (std::size_t i{0}; i < m_width; ++i) {
    m_cells[i] = new SpreadsheetCell[m_height];
  }

  for (std::size_t i{0}; i < m_width; ++i) {
    for (std::size_t j{0}; j < m_height; ++j) {
      m_cells[i][j] = rhs.m_cells[i][j];
    }
  }

  */
  return *this;
}

void Spreadsheet::swap(Spreadsheet& other) noexcept {
  std::swap(m_name, other.m_name);
  std::swap(m_width, other.m_width);
  std::swap(m_height, other.m_height);
  std::swap(m_cells, other.m_cells);
}

void swap(Spreadsheet& first, Spreadsheet& second) noexcept {
  first.swap(second);
}

// void Spreadsheet::cleanup() noexcept {
//  for (std::size_t i {0}; i< m_width; ++i) {
//    delete[] m_cells[i];
//  }
//  delete [] m_cells;
//  m_cells = nullptr;
//  m_width = m_height = 0;
// }
//
//
// void Spreadsheet::moveFrom(Spreadsheet& src) noexcept{
//
//  // Shallow copy of data
//  m_width = src.m_width;
//  m_height = src.m_height;
//  m_cells = src.m_cells;
//
//  // Reset the source object, because ownership has been moved!
//  /*
//  src.m_width = 0;
//  src.m_height = 0;
//  src.m_cells = nullptr;
//  */
//
//  // Move object data members
//  m_name = std::move(src.m_name);
//  // Move primitives
// m_width = std::exchange(src.m_width, 0);
// m_height = std::exchange(src.m_height, 0);
// m_cells = std::exchange(src.m_cells, nullptr);
// }

Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept {
  // moveFrom(src);

  swap(src);
}

std::size_t Spreadsheet::getCounter() { return ms_counter; }