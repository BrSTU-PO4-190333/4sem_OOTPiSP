#include "Person.hpp"

Person::Person()
{
    this->listPointerLeft = listHead;
    listHead = this;
    listLength += 1;

    this->name = new char[1];
    strcpy(this->name, "_");

    this->surname = new char[1];
    strcpy(this->surname, "_");
}

Person::Person(char* name, char* surname)
{
    this->listPointerLeft = listHead;
    listHead = this;
    listLength += 1;

    this->name = new char[strlen(name)];
    strcpy(this->name, name);

    this->surname = new char[strlen(surname)];
    strcpy(this->surname, surname);
}

Person::~Person()
{
    delete this->name;
    delete this->surname;
}

void Person::printList()
{
    cout << endl;
    cout << "[" << endl;
    for (Person* temp = listHead; temp != NULL; temp = temp->listPointerLeft)
    {
        temp->show();
    }
    cout << "]" << endl;
    cout << endl;
}

void Person::show()
{
    cout << "\t{" << endl
        << "\t\t" << "\"name\": \"" << this->name << "\"," << endl
        << "\t\t" << "\"surname\": \"" << this->surname << "\"," << endl
    << "\t}," << endl;
}
