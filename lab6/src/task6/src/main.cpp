#include <iostream>     //std::cout, std::endl
#include <exception>    //std::exception
#include <stdexcept>    //std::logic_error()
#include <cstring>      //std::string, std::to_string()
#include <cmath>        //log10()

double my_arcsin(double x);

int main()
{
    try
    {
        std::cout << "= = = = = start try = = = = =" << std::endl;

        std::cout << "arcsin(0.5) = " << my_arcsin(0.5) << std::endl;   //нет исключения
        std::cout << "arcsin(-55) = " << my_arcsin(-55) << std::endl;   //исключение default
        std::cout << "arcsin(-44) = " << my_arcsin(-44) << std::endl;   //исключение string
        std::cout << "arcsin(-33) = " << my_arcsin(-33) << std::endl;   //исключение char*
        std::cout << "arcsin(-22) = " << my_arcsin(-22) << std::endl;   //исключение int
        std::cout << "arcsin(-11) = " << my_arcsin(-11) << std::endl;   //исключение char
        std::cout << "arcsin(10) = " << my_arcsin(10) << std::endl;     //исключение exception

        std::cout << "= = = = = end try = = = = =" << std::endl;
    }
    catch(char value)
    {
        std::cout << "catch(char value) : " << value << std::endl;
    }
    catch(int value)
    {
        std::cout << "catch(int value) : " << value << std::endl;
    }
    catch(char* value)
    {
        std::cout << "catch(char* value) : " << value << std::endl;
    }
    catch(const char value[])
    {
        std::cout << "catch(char value[]) : " << value << std::endl;
    }
    catch(std::string value)
    {
        std::cout << "catch(std::string value) : " << value << std::endl;
    }
    catch(std::exception& ex)
    {
        std::cout << "catch(std::exception& ex) : " << ex.what() << std::endl;
    }
    catch(...)
    {
        std::cout << "catch(...)" << std::endl;
    }

    return 0;
}

double my_arcsin(double x)
{
    if (x == -11)
    {
        char ex = 'q';
        throw ex;
    }

    if (x == -22)
    {
        int ex = 22;
        throw ex;
    }

    if (x == -33)
    {
        char* ex = NULL;
        throw ex;
    }

    if (x == -44)
    {
        std::string ex = "str";
        throw ex;
    }

    if (x == -55)
    {
        float ex = 1.1;
        throw ex;
    }

    if (x > 1 || x < -1)
    {

        std::string msg = "x not in (0; +00) when func ln(x)";
        msg += " - because x = " + std::to_string(x) +  " in (-00; 0]";
        throw std::logic_error(msg);
    }

    return log10(x);
}