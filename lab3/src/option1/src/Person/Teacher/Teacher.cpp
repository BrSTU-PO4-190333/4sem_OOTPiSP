#include "Teacher.hpp"

Teacher::Teacher(const char* name, const char* surname, const char* subject)
{
    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->surname = new char[strlen(surname)];
    strcpy(this->surname, surname);

    this->subject = new char[strlen(subject)];
    strcpy(this->subject, subject);
}

Teacher::~Teacher()
{
    delete this->subject;
}

void Teacher::show()
{
    cout << "\t{" << endl
        << "\t\t" << "\"name\": \"" << this->name << "\"," << endl
        << "\t\t" << "\"surname\": \"" << this->surname << "\"," << endl
        << "\t\t" << "\"subject\": \"" << this->subject << "\"," << endl
    << "\t}," << endl;
}
