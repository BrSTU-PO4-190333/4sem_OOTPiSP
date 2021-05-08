#include "main.hpp"

Person* Person::listHead = NULL;
int Person::listLength = 0;

int main()
{
    Person p1 = Person();

    Student s1("Daniil", "Andreychikov", "PS-4");
    Student s2("Yana", "Baiduk", "PS-4");
    Student s3("Maxim", "Borovsky", "PS-4");
    Student s4("Anastasia", "Vorobey", "PS-4");
    Student s5("Pavel", "Galanin", "PS-4");
    Student s6("Dmitry", "Gribovsky", "PS-4");
    Student s7("Alexandra", "Gritsak", "PS-4");
    Student s8("Sergey", "Eliseev", "PS-4");
    Student s9("Zhuk", "Vladislav", "PS-4");
    Student s10("Ivan", "Ivanenko", "PS-4");
    Student s11("Vladimir", "Kalinovsky", "PS-4");
    Student s12("Vladislav", "Kovalchuk", "PS-4");
    Student s13("Stanislav", "Kotashevich", "PS-4");
    Student s14("Kirill", "Krechko", "PS-4");
    Student s15("Alexey", "Kydzela", "PS-4");
    Student s16("Alexey", "Lud", "PS-4");
    Student s17("Alexander", "Mayevsky", "PS-4");
    Student s18("Nikolay", "Pivnik", "PS-4");
    Student s19("Nikita", "Prokopyuk", "PS-4");
    Student s20("Danil", "Sinyak", "PS-4");
    Student s21("Denis", "Typik", "PS-4");
    Student s22("Anastasia", "Shiba", "PS-4");
    Student s23("Vladislav", "Yuriev", "PS-4");
    Student s24("Ilya", "Yakovchik", "PS-4");

    Teacher t1("Sergey", "Anfilets", "Programming languages");
    Teacher t2("Maria", "Khatskevich", "Programming languages");
    Teacher t3("Tatiana", "Glushchenko", "Discrete Math");
    Teacher t4("Ivan", "Gladki", "Hight Math");
    Teacher t5("Oksana", "Voitsekhovich", "Interface and software development technologies");
    Teacher t6("Alexander", "Kroshchenko", "Decision making methods and algorithms");

    HeadOfDepartment h1("Vladimir", "Golovko", "Intelligent information technology");

    p1.printList();

    return 0;
}
