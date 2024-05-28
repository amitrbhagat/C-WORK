#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    else
        return sum(n - 1) + n;
}

int Sum(int n)
{
    int i, s = 0;
    for (i = 1; i <= n; i++)

        s = s + i;
    return s;
}

int main()
{
    cout<<"for first sum"<<endl;
    cout << sum(5);
    cout << endl;
    cout << "for second sum" << endl;
    cout << Sum(5);

    return 0;
}