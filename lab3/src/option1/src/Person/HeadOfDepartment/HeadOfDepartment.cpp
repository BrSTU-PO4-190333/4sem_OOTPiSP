#include "HeadOfDepartment.hpp"

HeadOfDepartment::HeadOfDepartment(const char* name, const char* surname, const char* department)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->surname = new char[strlen(surname)];
    strcpy(this->surname, surname);

    this->department = new char[strlen(department)];
    strcpy(this->department, department);
}

HeadOfDepartment::~HeadOfDepartment()
{
    delete this->department;
}

void HeadOfDepartment::show()
{
    cout << "\t{" << endl
        << "\t\t" << "\"name\": \"" << this->name << "\"," << endl
        << "\t\t" << "\"surname\": \"" << this->surname << "\"," << endl
        << "\t\t" << "\"department\": \"" << this->department << "\"," << endl
    << "\t}," << endl;
}
