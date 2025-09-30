export module friends;

import std;

class Foo {
  friend class Bar;
  class FooFoo {
    public:
      int hello;
      class FooFooFoo {
        public:
          int world;
      };
  };

};

class Bar {};

export class TextHolder {
  public:

  explicit TextHolder(std::string text) : m_text{text} {}
  const std::string& getText(this const TextHolder& self)   { std::println("getText {}", self.m_text);return self.m_text; }
  std::string&& getText(this TextHolder&& self)  { std::println("getText && {}", self.m_text); return std::move(self.m_text); }
  TextHolder& operator=(this TextHolder& self, const std::string& rhs)  {self.m_text = rhs; return self;}
  int getCounter() { return m_counter; }
  private:
  std::string m_text;
    static int m_counter;
};  

int TextHolder::m_counter;