#include "Student.hpp"

Student::Student(const char* name, const char* surname, const char* group)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->surname = new char[strlen(surname)];
    strcpy(this->surname, surname);

    this->group = new char[strlen(group)];
    strcpy(this->group, group);
}

Student::~Student()
{
    delete this->group;
}

void Student::show()
{
    cout << "\t{" << endl
        << "\t\t" << "\"name\": \"" << this->name << "\"," << endl
        << "\t\t" << "\"surname\": \"" << this->surname << "\"," << endl
        << "\t\t" << "\"group\": \"" << this->group << "\"," << endl
    << "\t}," << endl;
}
