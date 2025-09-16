module Person;

import std;

void Person::setFirstName (std::string_view FirstName) {
  m_FirstName = FirstName;
}
void Person::setLastName (std::string_view LastName)
{
  m_LastName = LastName;
}

std::string Person::getFirstName () const{
  return m_FirstName;
}
std::string Person::getLastName()const {
  return m_LastName;
}