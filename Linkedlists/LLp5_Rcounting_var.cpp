#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int count(Node *p)
{
    int x = 0;
    if (p != 0)
    {
        x = count(p->next);
        return x + 1;
    }
    else
        return x;
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

    cout << count(first);
    return 0;
}
