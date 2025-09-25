export module friends;

import std;

class Foo {
  friend class Bar;
};

class Bar {};

export class TextHolder {
  public:
  explicit TextHolder(std::string text) : m_text{text} {}
  const std::string& getText() const & { std::println("getText {}", m_text);return m_text; }
  std::string&& getText() && { std::println("getText && {}", m_text); return std::move(m_text); }
  TextHolder& operator=(const std::string& rhs) & {m_text = rhs; return *this;}
  private:
  std::string m_text;
};