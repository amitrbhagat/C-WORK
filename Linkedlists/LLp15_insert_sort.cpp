#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void insert(Node *p, int x)
{
    Node *t = new Node;
    Node *q = NULL;
    p = first;
    t->data = x;

    if (first == NULL)
        first = t;

    else
    {
        while (p != 0 && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void display(Node *p)
{
    while (p != 0)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

int main()
{
    Node *second = NULL;
    Node *third = NULL;
    Node *fourth = NULL;

    first = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();

    first->data = 7;
    first->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    insert(first, 18);
    insert(first, 12);
    insert(first, 21);
    insert(first, 6);
    cout << endl;
    display(first);

    return 0;
}