#include <iostream>
using namespace std;

void funB(int n);
void funA(int n)
{
    if (n > 0)
    {
        cout << "\n"
             << n;
        funB(n - 1);
    }
}

void funB(int n)
{
    if (n > 1)
    {
        cout << "\n"
             << n;
        funA(n / 2);
    }
}

void funC(int n);
void funD(int n)
{
    if (n > 0)
    {
        cout << "\n"
             << n;
        funC(n - 1);
    }
}

void funC(int n)
{
    if (n > 1)
    {
        cout << "\n"
             << n;
        funD(n / 2);
    }
}

int main()
{

    int a = 20;
    funA(a);

    cout << endl;
    int b = 10;
    funD(b);
    return 0;
}