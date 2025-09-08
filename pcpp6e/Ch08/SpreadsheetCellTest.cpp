import std;
import spreadsheet_cell;
using namespace std;
int main() {
  SpreadsheetCell mySC;

  println("mySC.getValue()={}", mySC.getValue());
  mySC.setValue(3.0);
  println("now mySC.getValue()={}", mySC.getValue());

  mySC.setString("4.024");
  println("mySC.setString(\" 4.024 \");");
  println("now mySC.getValue()={}", mySC.getValue());
  println("now mySC.getString()={}", mySC.getString());
}