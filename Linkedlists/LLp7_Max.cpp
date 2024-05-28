#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int Max(Node *p)
{

    int m = -32768;
    while (p != 0)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
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

    cout << "the maximum element is:" << Max(first);
    return 0;
}