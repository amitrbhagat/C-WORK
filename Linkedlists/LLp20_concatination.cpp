#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

void concat(Node *p, Node *q)
{
    third = p;

    while (p->next != NULL)

        p = p->next;

    p->next = q;
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

    Node *t1 = NULL;
    Node *t2 = NULL;
    Node *t3 = NULL;
    Node *t4 = NULL;

    first = new Node();
    second = new Node();
    third = new Node();
    t1 = new Node();
    t2 = new Node();
    t3 = new Node();
    t4 = new Node();

    first->data = 7;
    first->next = t1;

    t1->data = 10;
    t1->next = t2;

    t2->data = 13;
    t2->next = NULL;

    second->data = 14;
    second->next = t3;

    t3->data = 15;
    t3->next = t4;

    t4->data = 20;
    t4->next = NULL;

    concat(first, second);
    cout << "the new linked list becomes:" << endl;
    display(third);

    return 0;
}