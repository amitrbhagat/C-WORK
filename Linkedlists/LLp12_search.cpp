
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

Node *search(Node *p, int key)
{

    Node *q;
    while (p != 0)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
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

    Node *t;
    t = search(first, 10);
    if (t != 0)
        cout << "key is found " << t->data;
    else
        cout << "not found ";
    cout << endl;
    display(first);

    return 0;
}