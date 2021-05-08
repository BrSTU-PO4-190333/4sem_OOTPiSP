#ifndef __HEADOFDEPARTMENT_HPP__
    #define __HEADOFDEPARTMENT_HPP__

    #include <iostream>
    #include <cstring>
    using namespace std;

    #include "../Person.hpp"

    class HeadOfDepartment: public Person
    {
        private:
            char* department;
        public:
            HeadOfDepartment(const char* name, const char* surname, const char* department);
            ~HeadOfDepartment();
            void show();
    };
#endif // __HEADOFDEPARTMENT_HPP__
