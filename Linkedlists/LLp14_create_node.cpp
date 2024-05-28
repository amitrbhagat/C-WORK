#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void insert(Node *p, int pos, int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    if (pos == 0)
    {
        t->next = first;
        first = t;
    }
    else if (pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1; i++)
        {
            if (p != 0)
                p = p->next;
        }
        if (p != 0)
        {

            t->next = p->next;
            p->next = t;
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

    // first->data = 7;
    // first->next = second;

    // second->data = 10;
    // second->next = third;

    // third->data = 15;
    // third->next = fourth;

    // fourth->data = 20;
    // fourth->next = NULL;

    insert(first, 0, 3);
    insert(first, 2, 4);
    insert(first, 3, 5);
    insert(first, 1, 10);
    display(first);
    return 0;
}