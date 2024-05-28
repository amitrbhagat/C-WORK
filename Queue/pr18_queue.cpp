#include <iostream>
using namespace std;

#define size 20

class stack
{
    int *st, top;
    int *Q1, *Q2;
    int front1, Rear1;
    int front2, Rear2;

public:
    stack()
    {
        top = -1;
        st = new int[size];
        Q1 = new int[size];
        Q2 = new int[size];
        front1 = Rear1 = -1;
        front2 = Rear2 = -1;
    }
    void push(int x);
    int pop();
    void enqueue1(int x);
    void enqueue2(int x);
    int dequeue1();
    int dequeue2();
    void display();
};

void stack::enqueue1(int x)
{
    if (Rear1 == size - 1)
        cout << "queue_1 is full" << endl;
    else
    {
        Rear1++;
        Q1[Rear1] = x;
    }
}

int stack::dequeue1()
{
    int x;
    if (front1 == Rear1)
        return 0;
    else
    {
        front1++;
        x = Q1[front1];
    }
    return x;
}

void stack::enqueue2(int x)
{
    if (Rear2 == size - 1)
        cout << "queue_2 is full" << endl;
    else
    {
        Rear2++;
        Q2[Rear2] = x;
    }
}

int stack::dequeue2()
{
    int x;
    if (front2 == Rear2)
        return 0;
    else
    {
        front2++;
        x = Q2[front2];
    }
    return x;
}

void stack::push(int x)
{
    if (front1 == Rear1)
        enqueue2(x);
    else
        enqueue1(x);
}

int stack::pop()
{
    int i, x;
    if (front2 == Rear2)
    {
        i = 0;
        while (i < Rear1)
        {
            x = dequeue1();
            enqueue2(x);
            i++;
        }
        return dequeue1();
    }
    else
    {
        i = 0;
        while (i < Rear2)
        {
            x = dequeue2();
            enqueue1(x);
            i++;
        }
        return dequeue2();
    }
}

void stack::display()
{
    int i;
    for (i = front2 + 1; i <= Rear2; i++)
        cout << Q2[i] << " ";
}

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.display();
    cout << "\n"
         << s.pop();
    return 0;
}