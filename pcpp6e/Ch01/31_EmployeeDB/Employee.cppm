/*

g++-15 -std=c++23 -fmodules-ts -fsearch-include-path bits/std.cc  -c -x c++ Employee.cppm

*/

export module employee;
import std;
namespace Records {
// The first constant represents the default starting salary for new
// employees. This constant is not
// exported, because code outside this module does not need access to it.

const int DefaultStartingSalary{30'000};
export const int DefaultRaiseAndDemeritAmount{1'000};

export class Employee {
 public:
  Employee(const std::string& firstName, const std::string& lastName);

  void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
  void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
  void hire();
  void fire();
  void display() const;

  // Getters and setters
  void setFirstName(const std::string& firstName);
  const std::string& getFirstName() const;

  void setLastName(const std::string& lastName);
  const std::string& getLastName() const;

  void setEmployeeNumber(int employeeNumber);
  int getEmployeeNumber() const;

  void setSalary(int newSalary);
  int getSalary() const;

  bool isHired() const;

 private:
  std::string m_firstName;
  std::string m_lastName;
  int m_employeeNumber{-1};
  int m_salary{DefaultStartingSalary};
  bool m_hired{false};
};
}  // namespace Records