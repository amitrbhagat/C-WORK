#include <iostream>
using namespace std;

#define size 20

class stack
{
    int top1;
    int *st1;
    int top2;
    int *st2;
    int *Q;
    int front, Rear;

public:
    stack()
    {
        top1 = -1;
        st1 = new int[size];
        top2 = -1;
        st2 = new int[size];
        Q = new int[size];
        front = Rear = -1;
    }
    void push1(int x);
    int pop1();
    void push2(int x);
    int pop2();
    void enqueue(int x);
    int dequeue();
    void display();
    void alternate();
    void DisplayAlternative();
};

void stack::push1(int x)
{
    if (top1 == size - 1)
        cout << "overflow1" << endl;
    else
    {
        top1++;
        st1[top1] = x;
    }
}

int stack::pop1()
{
    int x;
    if (top1 == -1)
        return 0;
    else
    {
        x = st1[top1];
        top1--;
    }
    return x;
}

void stack::push2(int x)
{
    if (top2 == size - 1)
        cout << "overflow2" << endl;
    else
    {
        top2++;
        st2[top2] = x;
    }
}

int stack::pop2()
{
    int x;
    if (top2 == -1)
        return 0;
    else
    {
        x = st2[top2];
        top2--;
    }
    return x;
}

void stack::enqueue(int x)
{
    push1(x);
}

int stack::dequeue()
{
    int x = -1;
    if (top2 == -1)
    {
        if (top1 == -1)
        {
            cout << "empty" << endl;
            return x;
        }
        else
        {
            while (top1 >= 0)
                x = pop1();
            push2(x);
        }
    }
    return pop2();
}

void stack::display()
{
    int i = top1;
    while (i >= 0)
    {
        cout << st1[i] << " ";
        i--;
    }
}
/*-------------------------------------------for alternative-------------------------------------*/
void stack::enqueue(int x)
{
    if (Rear == size - 1)
        cout << "queue is full" << endl;
    else
    {
        Rear++;
        Q[Rear] = x;
    }
}

int stack::dequeue()
{
    int x;
    if (front == Rear)
        return 0;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

void stack::alternate()
{
    int i, j, mid, length = 0, x, y;
    for (i = front + 1; i <= Rear; i++)
    {
        length++;
    }

    mid = length / 2;

    i = front + 1;
    while (i < mid)
    {
        x = dequeue();
        push1(x);
        i++;
    }
    j = mid;
    while (j <= Rear)
    {
        x = dequeue();
        push2(x);
        j++;
    }

    front = Rear = -1;
    while (top1 != -1)
    {
        x = pop1();
        enqueue(x);
    }
    while (top2 != -1)
    {
        y = pop2();
        enqueue(y);
    }

    i = front + 1;
    while (i < mid)
    {
        x = dequeue();
        push1(x);
        i++;
    }
    j = mid;
    while (j <= Rear)
    {
        x = dequeue();
        push2(x);
        j++;
    }

    front = Rear = -1;
    while (top1 != -1 && top2 != -1)
    {
        x = pop1();
        enqueue(x);
        y = pop2();
        enqueue(y);
    }
}

void stack::DisplayAlternative()
{
    for (int i = front + 1; i <= Rear; i++)
        cout << Q[i] << " ";
}

int main()
{
    stack s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.display();
    cout << "\n"
         << s.dequeue();
    /*-----------------------------------------------for Alternate-----------------------------------*/
    // s.enqueue(11), s.enqueue(12), s.enqueue(13), s.enqueue(14), s.enqueue(15),
    //     s.enqueue(16), s.enqueue(17), s.enqueue(18), s.enqueue(19), s.enqueue(20);
    // s.alternate();
    // s.DisplayAlternative();
    return 0;
}