#include <iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << "\n"
             << n;
    }
}

void fun2(int m)
{
    if (m > 0)
    {
        cout << "\n"
             << m;
        fun2(m - 1);
    }
}

int main()
{

    int x = 3;
    int y = 3;

    fun(x);
    cout << endl
         << endl
         << "for fun 2";
    fun2(y);

    return 0;
}