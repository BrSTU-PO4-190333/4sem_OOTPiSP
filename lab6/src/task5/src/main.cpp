#include <iostream>     //std::cout, std::endl
#include <cstring>      //std::string, std::to_string()

class Product
{
public:
    std::string model;
    std::string name;
    int onBox;
    float weight;
    float m3;

    Product(
        std::string model,
        std::string name,
        int onBox,
        float weight,
        float m3
    );
    ~Product();
};

int main()
{
    try
    {
        std::cout << "= = = = = start try = = = = =" << std::endl;

        Product a = Product("920100", "2 Gang Earthed Socket", 24, 2.09, 0.0087);
        Product b = Product("920102", "2 Gang Earthed Socket with 2m Cord", 12, 3.89, 0.0140);
        Product c = Product("920103", "2 Gang Earthed Socket with 3m Cord", 12, 5.08, 0.0161);

        int some_number = 0;
        if(some_number == 0)
        {
            throw 1.2345678;    // исключение;
        }

        Product d = Product("920105", "2 Gang Earthed Socket with 4m Cord", 12, 6.34, 0.0188);

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
    catch(...)
    {
        std::cout << "catch(...)" << std::endl;
    }

    return 0;
}

Product::Product(
    std::string model = "",
    std::string name = "",
    int onBox = 0,
    float weight = 0.0,
    float m3 = 0.0
)
{
    std::cout << this << " constructor" << std::endl;
    this->model = model;
    this->name = name;
    this->onBox = onBox;
    this->weight = weight;
    this->m3 = m3;
}

Product::~Product()
{
    std::cout << this << " destructor" << std::endl;
}