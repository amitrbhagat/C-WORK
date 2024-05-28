#include <iostream>
using namespace std;

int fib(int n)
{
    int t0 = 0, t1 = 1;
    int s = 0;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int rfib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 2) + fib(n - 1);
}

int f[10];
int fib1(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 2] == -1)
            f[n - 2] = fib1(n - 2);
        if (f[n - 1] == -1)
            f[n - 1] = fib1(n - 1);
        f[n] = f[n - 2] + f[n - 1];
        return f[n - 2] + f[n - 1];
    }
}

int main()
{
    // cout << fib(7);
    // cout << endl;
    // cout << fib(6);
    // cout << endl;
    // cout << "for rfib" << endl;
    // cout << fib(7);

    int i;
    for (i = 0; i <= 10; i++)
        f[i] = -1;
    cout << fib1(7);
    cout << endl;
    cout << fib1(6);

    return 0;
}