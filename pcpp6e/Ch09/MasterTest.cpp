import std;
using namespace std;
import spreadsheet;
import spreadsheet_cell;
import friends;

/*
void handleMessage(string& message) { // lvalue reference parameter
  println("handleMessage with lvalue reference: {}", message);
}
*/

void handleMessage(string&& message) {  // rvalue reference parameter
  println("handleMessage with rvalue reference: {}", message);
}

Spreadsheet createObject() { return Spreadsheet{2, 3}; }

TextHolder makeTextHolder() {
  return TextHolder{"Hello from makeTextHolder()"};
}
// It works because getArraySize() is a constant expression. as at 2025-09-28
const int getArraySize() { return 32; }

void log(std::string_view message) { std::println("Log: {}", message); }

constexpr int computeSomething(bool someFlag) {
  if (someFlag) {
    log("computeSomething: true");
    return 42;
  } else {
    return 84;
  }
}
int main() {
  // constexpr auto value1{computeSomething(true)}; // does not compile as
  // value1 is evaluated at compile time
  constexpr auto value1{computeSomething(false)};

  const auto value3{
      computeSomething(true)};  // OK: value3 is evaluated at runtime

  int myArray[getArraySize() +
              1];  // OK: getArraySize() is a constant expression
  std::println("myArray size: {}", sizeof(myArray));

  /*
  string a{"Hello"};

  // You can force the compiler to call the rvalue reference overload of
  // handleMessage()  by using std::move().The only thing move() does is cast an
  // lvalue to an rvalue reference;
  // that is, it does not do any actual moving.

  handleMessage(std::move(a));  // Calls handleMessage(string&& value)
  // cast lvalue to rvalue reference

  string b{"World"};
  handleMessage(std::move(b));

  handleMessage("yo baby");
*/

  vector<Spreadsheet> vec;
  for (size_t i{0}; i < 2; ++i) {
    println("Iteration {}", i);
    vec.push_back(Spreadsheet{100, 100});
    println("");
  }
  Spreadsheet ss{2, 3};
  println("ss.getCounter()1: {}", ss.getCounter());

  ss = createObject();
  println("ss.getCounter()2: {}", ss.getCounter());

  println("");

  Spreadsheet s2{5, 6};
  println("s2.getCounter()1: {}", s2.getCounter());
  s2 = ss;
  println("s2.getCounter()2: {}", s2.getCounter());

  s2.incrementCounter();
  println("s2.getCounter()3: {}", s2.getCounter());
  println("ss.getCounter()3: {}", ss.getCounter());
  ss.incrementCounter();
  println("s2.getCounter()4: {}", s2.getCounter());
  println("ss.getCounter()4: {}", ss.getCounter());

  SpreadsheetCell s{1.2};
  SpreadsheetCell s1{3.14159};
  auto s3{s + s1};
  println("s.getValue(): {}", s.getValue());
  println("s.getString(): {}", s.getString());
  println("s1.getValue(): {}", s1.getValue());
  println("s1.getString(): {}", s1.getString());
  println("s3.getValue(): {}", s3.getValue());
  println("s3.getString(): {}", s3.getString());

  s.set(123.456);
  println("s.getValue(): {}", s.getValue());
  println("s.getString(): {}", s.getString());
  s.set("890.123");
  println("s.getValue(): {}", s.getValue());
  println("s.getString(): {}", s.getString());

  s.set(5473);
  println("s.getValue(): {}", s.getValue());
  println("s.getString(): {}", s.getString());

  TextHolder th{"Hello, TextHolder!"};
  println("th.getText(): {}", th.getText());

  println("{}", TextHolder{"Temporary TextHolder"}.getText());

  auto th2 = makeTextHolder();
  th2 = "New text for th2";
  println("th2.getText(): {}", th2.getText());

  SpreadsheetCell myCell{4}, aThirdCell;
  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  string str{"hello"};
  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  // aThirdCell = myCell + string_view{str};
  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  aThirdCell = myCell + 5.6;
  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  aThirdCell = myCell + 4;

  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  aThirdCell = 6 + myCell;  // failed to compile ok
  println("aThirdCell.getValue(): {}", aThirdCell.getValue());
  println("aThirdCell.getString(): {}", aThirdCell.getString());
  return 0;
}