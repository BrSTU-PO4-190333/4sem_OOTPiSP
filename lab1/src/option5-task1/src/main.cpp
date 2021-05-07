#include <iostream>
#include <cmath>

using namespace std;

void print(float &f, double &d);
void option5_task1();

int main()
{
    option5_task1();

    return 0;
}

void print(float &f, double &d)
{
    cout << f << " - float" << endl;
    cout << d << " - double" << endl;

    printf("%80.40f - float\n", f);
    printf("%80.40lf - double\n", d);

    for (int i = 0; i < 40; i++) cout << " =";
    cout << endl;
}

void option5_task1()
{
    cout << "a = 1000" << endl;
    float fa = 1000;
    double da = 1000;
    print(fa, da);

    cout << "b = 0.0001" << endl;
    float fb = 0.0001;
    double db = 0.0001;
    print(fb, db);

    cout << "x1 = a - b" << endl;
    float f1 = fa - fb;
    double d1 = da - db;
    print(f1, d1);

    cout << "x2 = (a-b)^3 = x1^3" << endl;
    float f2 = pow(f1, 3);
    double d2 = pow(d1, 3);
    print(f2, d2);

    cout << "x3 = a^3" << endl;
    float f3 = pow(fa, 3);
    double d3 = pow(da, 3);
    print(f3, d3);

    cout << "x4 = 3*a*a*b" << endl;
    float f4 = 3 * fa * fa * fb;
    double d4 = 3 * da * da * db;
    print(f4, d4);

    cout << "x5 = x3 - x4" << endl;
    float f5 = f3 - f4;
    double d5 = d3 - d4;
    print(f5, d5);

    cout << "x6 = x2 - x5" << endl;
    float f6 = f2 - f5;
    double d6 = d2 - d5;
    print(f6, d6);

    cout << "x7 = b^3" << endl;
    float f7 = pow(fb, 3);
    double d7 = pow(db, 3);
    print(f7, d7);

    cout << "x8 = 3*a*b*b" << endl;
    float f8 = 3 * fa * fb * fb;
    double d8 = 3 * da * db * db;
    print(f8, d8);

    cout << "x9 = b^3 - 3*a*b*b = x7 - x8" << endl;
    float f9 = f7 - f8;
    double d9 = d7 - d8;
    print(f9, d9);

    cout << "x10 = ( (a-b)^3 - (a^3-3*a*a*b) ) / ( b^3 - 3*a*b*b ) = x6 / x9" << endl;
    float f10 = f6 / f9;
    double d10 = d6 / d9;
    print(f10, d10);

    cout << endl;
    cout << "Answer: (float) " << f10 << endl;
    cout << "Answer: (double) " << d10 << endl;
}