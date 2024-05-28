#include <iostream>
using namespace std;

#define size 50

class stack
{
    int *st;
    int top;

public:
    stack()
    {
        st = new int[size];
        top = -1;
    }
    void push(int x);
    int pop();
    int peek(int pos);
    int isEmpty();
    int isFull();
    int stacktop();
    void display();
};

void stack::push(int x)
{
    if (top == size)
        cout << "stack is full" << endl;
    else
    {
        top++;
        st[top] = x;
    }
}

int stack::pop()
{
    int x = -1;
    if (top == -1)
        cout << "stack is empty" << endl;
    else
    {
        x = st[top];
        top--;
    }
    return x;
}

void stack::display()
{
    int i;
    for (i = top; i >= 0; i--)
        cout << st[i] << " ";
}

int stack::peek(int pos)
{
    int x = -1;
    if (top - pos + 1 < 0)
        cout << "invalid position" << endl;
    else
    {
        x = st[top - pos + 1];
    }
    return x;
}

int stack::isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int stack::isFull()
{
    if (top == size)
        return 1;
    else
        return 0;
}

int stack::stacktop()
{
    if (isEmpty())
        return 0;
    else
        return st[top];
}

int main()
{
    stack st;
    st.push(10), st.push(20), st.push(30), st.push(40), st.push(50), st.push(60), st.push(70), st.push(80);
    st.pop();
    st.display();
    // cout << st.peek(2);
    // cout << " " << st.isEmpty() << " " << st.isFull() << " " << st.stacktop();

    return 0;
}