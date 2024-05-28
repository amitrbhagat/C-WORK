#include <iostream>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int nCr(int n, int r)
{
    int num, den;
    num = fact(n);
    den = fact(r) * fact(n - r);
    return num / den;
}

int C(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return C(n - 1, r - 1) + C(n - 1, r);
}

int main()
{
    cout << nCr(5, 2);
    cout << endl;
    cout << nCr(4, 2);
    cout << endl;
    cout << C(5, 2);

    return 0;
}