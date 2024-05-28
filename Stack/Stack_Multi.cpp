#include <iostream>
using namespace std;

#define size 80

class stack
{
    int *st;
    int topA;
    int topB;

public:
    stack()
    {
        st = new int[size];
        topA = -1;
        topB = size;
    }

    void pushA(int x)
    {
        if (topA + 1 == topB || topA == size || topB == -1)
            cout << "overflow";
        else
        {
            topA++;
            st[topA] = x;
        }
    }

    void pushB(int x)
    {
        if (topA + 1 == topB || topA == size || topB == -1)
            cout << "overflow";
        else
        {
            if (topB == 0)
            {
                topB = size;
            }
            else
            {
                topB--;
            }
            st[topB] = x;
        }
    }
    void popA()
    {
        int x;
        if (topA == -1)
            cout << "stack underflow";
        else
        {
            x = st[topA];
            topA--;
        }
    }
    void popB()
    {
        int x;
        if (topB == 0)
            cout << "underflow";
        else
        {
            x = st[topB];
            if (topB == size)
            {
                topB = 0;
            }
            else
            {
                topB++;
            }
        }
    }

    void display()
    {
        int i, j;
        for (int i = 0; i <= topA; i++)
            cout << st[i] << "\n";
        for (int j = topB; j < size; j++)
            cout << st[j] << "\n";
    }
};

int main()
{
    stack stk;

    cout << "push the element" << endl;
    stk.pushA(10);
    stk.pushA(20);
    stk.pushA(30);
    stk.pushA(40);

    stk.pushB(110);
    stk.pushB(120);
    stk.pushB(130);
    stk.pushB(140);
    stk.display();

    cout << "after poping element becomes" << endl;
    stk.popA();
    stk.popB();
    stk.display();

    return 0;
}