#include <iostream>
using namespace std;

class myCharSet
{
private:
    char* arr;
    int length;
public:
    myCharSet();
    ~myCharSet();
    void add(char ch);
    void print();
    friend myCharSet operator+(const myCharSet& obj1, const myCharSet& obj2);
    friend bool operator<=(const myCharSet &obj1, const myCharSet &obj2);
};

int main()
{
    myCharSet x1 = myCharSet();
    cout << "x1" << endl;
    x1.add('c');
    x1.add('a');
    x1.add('b');
    x1.add('b');
    x1.add('c');
    x1.add('c');
    x1.print();

    myCharSet x2 = myCharSet();
    cout << "x2" << endl;
    x1.add('c');
    x2.add('a');
    x2.add('d');
    x2.add('c');
    x2.add('d');
    x2.print();

    cout << "(x1 <= x2) = " << (x1 <= x2) << endl << endl;
    cout << "(x2 <= x1) = " << (x2 <= x1) << endl << endl;
    cout << "(x1 <= x1) = " << (x1 <= x1) << endl << endl;

    cout << "x3" << endl;
    myCharSet x3 = myCharSet();
    x3.add('g');
    x3.add('d');
    x3.add('u');
    x3.add('w');
    x3.print();

    cout << "x4" << endl;
    myCharSet x4 = myCharSet();
    x4.add('t');
    x4.add('l');
    x4.add('s');
    x4.add('d');
    x4.print();

    cout << "x5 = x3 + x4" << endl;
    myCharSet x5 = x3 + x4;
    x5.print();

    return 0;
}

myCharSet::myCharSet()
{
    cout << this << " constructor" << endl;
    this->length = 0;
    char* arr = new char [this->length];
    this->arr = arr;
}

myCharSet::~myCharSet()
{
    cout << this << " destructor" << endl;
    delete [] arr;
}

void myCharSet::add(char ch)
{
    int k = 0;
    for (int i = 0; i < this->length; i++)
    {
        if (ch == this->arr[i])
        {
            k += 1;
        }
    }

    if (k == 0)
    {
        this->length += 1;
        char* newArr = new char [this->length];
        newArr[this->length - 1] = ch;
        for (int i = 0; i < this->length; i++)
        {
            newArr[i] = this->arr[i];
        }
        delete [] this->arr;
        newArr[this->length - 1] = ch;
        this->arr = newArr;
    }

    for (int i = 0; i < this->length; i++)
    {
        for (int j = 0; j < this->length; j++)
        {
            if (this->arr[i] < this->arr[j])
            {
                int temp = this->arr[i];
                this->arr[i] = this->arr[j];
                this->arr[j] = temp;
            }
        }
    }
}

void myCharSet::print()
{
    printf("[ ");
    for (int i = 0; i < this->length; i++)
    {
        printf("%c, ", this->arr[i]);
    }
    printf("]\n\n");
}

bool operator<=(const myCharSet &obj1, const myCharSet &obj2)
{
    int length = min(obj1.length, obj2.length);

    for (int i = 0; i < length; i++)
    {
        if (obj1.arr[i] > obj2.arr[i])
        {
            return false;
        }
    }

   return true;
}

myCharSet operator+(const myCharSet& obj1, const myCharSet& obj2)
{
    myCharSet obj = myCharSet();

    for (int i = 0; i < obj1.length; i++)
    {
        obj.add(obj1.arr[i]);
    }
    for (int i = 0; i < obj2.length; i++)
    {
        obj.add(obj2.arr[i]);
    }

    return obj;
}