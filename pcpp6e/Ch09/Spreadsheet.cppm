export module spreadsheet;

import std;

export import spreadsheet_cell;
/*

  Rule of five
  1. Destructor
  2. Copy constructor
  3. Copy assignment operator
  4. Move constructor
  5. Move assignment operator

  If you need to explicitly declare any of the five, you probably need to
  explicitly declare all five.

  If your class does not manage resources (memory, file handles, network
  connections, etc.), you probably don't need to declare any of the five.

  If your class manages resources, you need to ensure that the resources are
  properly copied, moved, and released in all scenarios.

  The copy-and-swap idiom is a technique for implementing the copy assignment
  operator in a way that is safe and efficient. It involves three steps:

  1. Create a copy of the right-hand side object (the one being assigned from).
     This is done using the copy constructor.
  2. Swap the contents of the current object with the copy. This is done using a
     swap function.
  3. When the function exits, the copy goes out of scope and its destructor is
     called, releasing any resources it holds.

  This approach has several advantages:
  - Exception safety: If an exception is thrown during the copy construction,
    the current object remains unchanged.
  - Self-assignment safety: The check for self-assignment is not needed because
    swapping an object with itself has no effect.
  - Code reuse: The copy constructor and swap function can be reused in other
    contexts.
    */

export class Spreadsheet {
 public:
  Spreadsheet(Spreadsheet&& src) noexcept;  // Move constructor

  Spreadsheet& operator=(const Spreadsheet& rhs);
  Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;  // Move constructor

  Spreadsheet(std::size_t width, std::size_t height);
  Spreadsheet(const Spreadsheet& src);
  void setCellAt(std::size_t x, std::size_t y, const SpreadsheetCell& cell);
  SpreadsheetCell& getCellAt(std::size_t x, std::size_t y);
  std::size_t getCounter();
  void swap(Spreadsheet& other) noexcept;
  void incrementCounter() { ++ms_counter; }
  ~Spreadsheet();

 private:
  // void cleanup() noexcept;
  // void moveFrom(Spreadsheet& src) noexcept;
  bool inRange(std::size_t value, std::size_t upper) const;
  void verifyCoordinate(std::size_t x, std::size_t y) const;
  static inline std::size_t
      ms_counter;  // C++17 後要加 inline 如果唔係會有 link error
  std::size_t m_width{0};
  std::size_t m_height{0};
  SpreadsheetCell** m_cells{nullptr};

  std::string m_name{};
};

export void swap(Spreadsheet& first, Spreadsheet& second) noexcept;