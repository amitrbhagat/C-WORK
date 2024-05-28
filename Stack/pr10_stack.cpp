#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *top = NULL, *first = NULL;

void pushA(int x)
{
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
}

void pushB(int x)
{
    Node *q = new Node;
    if (q == NULL)
        cout << "overflow"
             << " ";
    else
    {
        q->data = x;
        q->next = first;
        first = q;
    }
}

int popA()
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
    }
    return x;
}

int popB()
{
    Node *q;
    int x = -1;
    if (first == NULL)
        return 0;
    else
    {
        q = first;
        x = q->data;
        first = first->next;
        delete q;
    }
    return x;
}

void mergePoint(Node *p, Node *q)
{
    int x;
    while (p->data == q->data)
    {
        x = p->data;
        popA();
        popB();
        p = top;
        q = first;
    }
    cout << x;
}

void display(Node *p, Node *q)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
    while (q != NULL)
    {
        cout << q->data << " ";
        q = q->next;
    }
}

int main()
{
    pushA(20), pushA(30), pushA(40), pushA(50);
    pushB(60), pushB(70), pushB(30), pushB(40), pushB(50);
    display(top, first);
    cout << "\n";
    mergePoint(top, first);
}