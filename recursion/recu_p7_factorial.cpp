#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;

    return fact(n - 1) * n;
}

int fact1(int n)
{
    int f = 1, i;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}

int main()
{

    int a = 5;
    cout << fact1(a);

    int b = 4;
    cout << "\n"
         << fact(b);

    return 0;
}