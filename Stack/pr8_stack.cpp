#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *top = NULL, *first = NULL;

void push(int x)
{
    Node *q = new Node;
    Node *t = new Node;
    if (t == NULL)
        cout << "overflow"
             << " ";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
    if (first == NULL || first->data >= x)
    {
        q->data = x;
        q->next = first;
        first = q;
    }
    else
    {
        q->data = first->data;
        q->next = first;
        first = q;
    }
}

int pop()
{
    Node *p;
    int x = -1;
    if (top == NULL)
        return 0;
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
        p = first;
        first = first->next;
        delete p;
    }
    return x;
}

int Getminimum()
{
    return first->data;
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void Display(Node *q)
{
    while (q != NULL)
    {
        cout << q->data << "\n";
        q = q->next;
    }
}

int main()
{
    push(2), push(6), push(4), push(1), push(5);
    display(top);
    pop(), pop(), pop();
    cout << "\n"
         << Getminimum();
    return 0;
}