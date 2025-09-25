export module spreadsheet;

import std;

export import spreadsheet_cell;
import std;

export class Spreadsheet {
 public:
  Spreadsheet(Spreadsheet&& src) noexcept;  // Move constructor

  Spreadsheet& operator=(const Spreadsheet& rhs);
  Spreadsheet& operator=(Spreadsheet&& rhs) noexcept; // Move constructor 
  
  Spreadsheet(std::size_t width, std::size_t height);
  Spreadsheet(const Spreadsheet& src);
  void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
  SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);

  void swap(Spreadsheet& other) noexcept;
  ~Spreadsheet();

 private:
  // void cleanup() noexcept;
  // void moveFrom(Spreadsheet& src) noexcept;
  bool inRange(std::size_t value, std::size_t upper) const;
  void verifyCoordinate(std::size_t x, std::size_t y) const;
  std::size_t m_width{0};
  std::size_t m_height{0};
  SpreadsheetCell** m_cells{nullptr};

  std::string m_name{};
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;