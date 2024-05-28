#include <iostream>
using namespace std;

int fun(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int fun2(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return fun2(n - 1) + x;
    }
    return 0;
}
int fun3(int n)
{
   
    if (n > 0)
    {
        
        return fun3(n - 1) + n;
    }
    return 0;
}

int main()
{

    int r = 5;
    cout << fun(r);

    r = fun(5);
    cout << "\n"
         << r;

    int a = 3;
    cout << "\n"
         << fun2(a);

         int b=3;
         cout<<"\n"<<fun3(b);

    return 0;
}