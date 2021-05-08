cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

add_executable(
    main
    src/main.cpp
    src/main.hpp
    src/Person/Person.cpp
    src/Person/Person.hpp
    src/Person/HeadOfDepartment/HeadOfDepartment.cpp
    src/Person/HeadOfDepartment/HeadOfDepartment.hpp
    src/Person/Student/Student.cpp
    src/Person/Student/Student.hpp
    src/Person/Teacher/Teacher.cpp
    src/Person/Teacher/Teacher.hpp
)