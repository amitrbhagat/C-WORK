#include <iostream>
using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        cout << "\n"
             << n;
        fun(n - 1);
        fun(n - 1);
    }
}

void fun1(int n)
{
    if (n > 0)
    {
        cout << "\n"
             << n;
        fun1(n - 1);
        fun1(n - 1);
    }
}

int main()
{

    int y = 3;
    fun(y);

    cout << endl;
    int x = 2;
    fun1(x);
    return 0;
}