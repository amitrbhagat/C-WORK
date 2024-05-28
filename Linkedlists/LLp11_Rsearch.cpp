#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *search(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return search(p->next, key);
}

int main()
{
    Node *first = NULL;
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
    t = search(first, 20);
    if (t != 0)
        cout << "key is found " << t->data;
    else
        cout << "not found ";
    return 0;
}