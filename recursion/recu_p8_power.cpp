#include <iostream>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
        return 1;
    else
        return power(m, n - 1) * m;
}

int power1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n / 2);

    return m * power1(m * m, (n - 1) / 2);
}

int pow(int x, int y)
{
    int i;
    int result = 1;
    for (i = 1; i <= y; i++)
        result = result * x;
    return (result);
}

int main()
{

    int a = 2, b = 3;
    cout << power(a, b);

    cout << endl;
    int c = 3, d = 2;
    cout << power1(c, d);

    int x = 2, y = 3;
    cout << "\n"
         << pow(x, y);

    return 0;
}