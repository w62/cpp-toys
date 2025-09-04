/*
g++-15 -std=c++23 -fmodules-ts -c -x c++ employee.cppm
g++-15 -std=c++23 -fmodules -fsearch-include-path bits/std.cc  -o hello structest.cpp employee.o

*/
import std;
import employee;

using namespace std;

int main() {
  // Create and populate an employee.
  Employee anEmployee;
  anEmployee.firstInitial = 'J';
  anEmployee.lastInitial = 'D';
  anEmployee.employeeNumber = 42;
  anEmployee.employeeNumber = 80000;
  // Output the values of an employee.
  println("Employee: {}{}", anEmployee.firstInitial, anEmployee.lastInitial);
  println("Number: {}", anEmployee.employeeNumber);
  println("Salary: ${}", anEmployee.salary);
}