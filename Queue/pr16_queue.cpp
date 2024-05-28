#include <iostream>
using namespace std;
#define size 20

class stack
{
    int top;
    int *st;
    int *Q;
    int front, rear;

public:
    stack()
    {
        top = -1;
        st = new int[size];
        Q = new int[size];
        front = rear = -1;
    }
    void push(int x);
    int pop();
    void enqueue(int x);
    int dequeue();
    void reverse();
    int pair();
    void MinAlternative();
    void display();
};

void stack::push(int x)
{
    if (top == size - 1)
        cout << "overflow" << endl;
    else
    {
        top++;
        st[top] = x;
    }
}

int stack::pop()
{
    int x;
    if (top == -1)
        return 0;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

void stack::enqueue(int x)
{
    if (rear == size - 1)
        cout << "full" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int stack::dequeue()
{
    int x;
    if (front == rear)
        cout << "empty" << endl;
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}

void stack::display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
        cout << Q[i] << " ";
}

void stack::reverse()
{
    int i, x;
    for (i = front + 1; i <= rear; i++)
    {
        push(Q[i]);
    }
    while (top >= 0)
    {
        x = pop();
        cout << x << " ";
    }
}

int stack::pair()
{
    int pairorder = 1, x, m, n;
    while (top != -1)
    {
        x = pop();
        enqueue(x);
    }
    while (front < rear)
    {
        x = dequeue();
        push(x);
    }
    while (top != -1)
    {
        n = pop();
        enqueue(n);
        if (top != -1)
        {
            m = pop();
            enqueue(m);
            if (abs(n - m) != 1)
            {
                pairorder = 0;
            }
        }
    }
    return pairorder;
}

void stack::MinAlternative()
{
    int i, x, length = 0, k = 4;
    for (i = front + 1; i <= rear; i++)
    {
        length++;
    }
    for (i = 0; i < k; i++)
    {
        x = dequeue();
        push(x);
    }
    while (top != -1)
    {
        x = pop();
        enqueue(x);
    }
    for (i = 0; i < length - k; i++)
    {
        x = dequeue();
        enqueue(x);
    }
}

int main()
{
    stack s;
    // s.enqueue(10),s.enqueue(20),s.enqueue(30),s.enqueue(40),s.enqueue(50);
    // s.reverse();
    /*-------------------------------------------------------------------------------------------------*/
    // s.push(4), s.push(5), s.push(-2), s.push(-3), s.push(11);
    // s.push(10), s.push(5), s.push(6), s.push(20);
    // cout << s.pair();
    /*-------------------------------------------------------------------------------------------------*/
    s.enqueue(20), s.enqueue(30), s.enqueue(10), s.enqueue(40), s.enqueue(50), s.enqueue(60), s.enqueue(70),
        s.enqueue(80), s.enqueue(90);
    s.MinAlternative();
    s.display();
    return 0;
}