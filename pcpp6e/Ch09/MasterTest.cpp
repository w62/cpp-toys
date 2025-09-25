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

  Spreadsheet createObject() {
    return Spreadsheet{2,3};
  }

  TextHolder makeTextHolder() {
    return TextHolder{"Hello from makeTextHolder()"};
  }
int main() {
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
  for (size_t i {0}; i <2; ++i){
    println("Iteration {}", i);
    vec.push_back(Spreadsheet{100, 100});
    println("");
  }
  Spreadsheet ss {2, 3};

  ss = createObject();

  println("");

  Spreadsheet s2 {5,6};
  s2 = ss;

  SpreadsheetCell s;
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
  return 0;
}