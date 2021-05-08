#ifndef __PERSON_HPP__
    #define __PERSON_HPP__

    #include <iostream>
    #include <cstring>
    using namespace std;

    class Person
    {
        private:
            Person* listPointerLeft;
        protected:
            char* name;
            char* surname;
        public:
            static Person* listHead;
            static int listLength;

            Person();
            Person(char* name, char* surname);
            ~Person();
            void printList();
            // Если убрать virtual, то функция, которая вызовет this->show() вызовет только эту функцию,
            // Если слово virtual оставить, то если в наследованом классе есть такой метод show(),
            // то сработает именно новый метод show(), а не этот
            virtual void show();
    };
#endif // __PERSON_HPP__
