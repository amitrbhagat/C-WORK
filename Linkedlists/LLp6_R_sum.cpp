#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int Add(Node *p)
{
    if (p == 0)
        return 0;
    else
        return Add(p->next) + p->data;
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

    cout << "total addition is: " << Add(first);

    return 0;
}