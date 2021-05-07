#include <iostream>

using namespace std;

void option5_task2();

int main()
{
    option5_task2();

    return 0;
}

void option5_task2()
{
    int n, m;

    //subtask 1
    n = 1;
    m = 1;
    puts("1) - -n-++m");

    printf("\tn = %d\n", n);
    printf("\tm = %d\n", m);

    puts("- -n-++m = ");
    puts("\t= (- - n) - (++m) = ");
    puts("\t= n - (m+1) = ");
    puts("\t= 1 - (1+1) = 1 - 2 = -1");
    printf("\t= %d - (%d+1) = %d - %d = %d\n", n, m, n, m+1, n-(m+1));

    cout << "Answer: " << - -n-++m << endl << endl;

    //subtask 2
    n = 1;
    m = 1;
    puts("2) m*n<n++");

    printf("\tn = %d\n", n);
    printf("\tm = %d\n", m);

    puts("m*n<n++");
    puts("\t(m * n) < n");
    printf("\t(%d * %d) < %d\n", m,n,n);
    printf("\t%d < %d\n", m*n, n);

    cout << "Answer: " << (m*n<n++) << endl << endl;

    //subtask 3
    n = 1;
    m = 1;
    puts("3) n-- > m++");

    printf("\tn = %d\n", n);
    printf("\tm = %d\n", m);

    puts("n-- > m++");
    puts("\tn > m");
    printf("\t%d > %d\n", n, m);

    cout << "Answer: " << (n-- > m++) << endl << endl;
}