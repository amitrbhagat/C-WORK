#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *top = NULL;

void push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "stack is full" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    Node *t;
    int x = -1;
    if (top == NULL)
        cout << "stack is empty" << endl;
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

int peek(Node *p, int pos)
{
    int i;
    for (i = 1; i < pos; i++)
    {
        if (p != NULL)
        {
            p = p->next;
        }
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

int stacktop()
{
    if (top == NULL)
        return -1;
    else
        return top->data;
}

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull()
{
    Node *t = new Node;
    t->data = 10;
    if (t == NULL)
        return 1;
    return 0;
}

Node *search(int key)
{
    Node *p = top;
    while (p != NULL && p->data != key)
    {
        p = p->next;
    }
    if (p == NULL)
        return 0;
    else
        return p;
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void decimal(int num)
{
    int x, y;
    while (num != 0)
    {
        x = num % 2;
        push(x);
        num = num / 2;
    }
    while (top != NULL)
    {
        cout << pop() << " ";
    }
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int Eval(char postfix[])
{
    int i, x1, x2, r = 0;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            }
            push(r);
        }
    }
    return pop();
}

int main()
{
    // push(20);
    // push(30);
    // push(40);
    // push(50);
    // push(60);
    // pop();
    // display(top);
    // cout << peek(top, 3) << " ";
    // cout << isEmpty() << " ";
    // cout << isFull() << " ";
    // cout << stacktop() << " ";
    // cout << search(40) << " ";
    // decimal(32);
    char postfix[] = "234*+82/-";
    cout << " " << Eval(postfix);
    return 0;
}