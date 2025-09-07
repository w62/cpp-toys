/*

*/

module database;
import std;


using namespace std;

namespace Records {


Employee& Database::addEmployee(const std::string& firstName,
                                const std::string& lastName) {
  Employee theEmployee{firstName, lastName};
  theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
  theEmployee.hire();
  m_employees.push_back(theEmployee);
  return m_employees.back();
  // The back() member function of vector returns a reference
  // to the last element in the vector, which is the newly added employee.
}
Employee& Database::getEmployee(int employeeNumber) {
  for (auto& employee : m_employees) {
    // Notice the use of auto& in the rangebased for loop,
    // because the loop doesn’t want to work with copies of Employees
    // but with references to the Employees in the m_employees vector.
    if (employee.getEmployeeNumber() == employeeNumber) {
      return employee;
    }
  }
  throw logic_error{"No employee found. employeeNumber:"};
}

Employee& Database::getEmployee(const std::string& firstName,
                                const std::string& lastName) {
  for (auto& employee : m_employees) {
    if (employee.getFirstName() == firstName && employee.getLastName() == lastName) {
      return employee;
    }
  }
  throw logic_error{"No employee found. Name"};
}

void Database::displayAll() const {
  for (const auto& employee : m_employees) {
    employee.display();
  }
}

void Database::displayCurrent() const {
  for (const auto& employee : m_employees) {
    if (employee.isHired()) {
      employee.display();
    }
  }
}
void Database::displayFormer() const {
  for (const auto& employee : m_employees) {
    if (!employee.isHired()) {
      employee.display();
    }
  }
}
}  // namespace Records