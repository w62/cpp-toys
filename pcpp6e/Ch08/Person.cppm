export module Person;

import std;

export class Person {
public:
void setFirstName (std::string_view FirstName);
void setLastName (std::string_view LastName);

std::string getFirstName () const;
std::string getLastName()const ;

private:
std::string m_FirstName;
std::string m_LastName;
};