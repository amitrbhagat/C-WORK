#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

int RMax(Node *p)
{
    int x = 0;
    if (p == 0)
        return x;
    else
    {
        x = RMax(p->next);
        if (x > p->data)
            return x;
        else
            return p->data;
    }
}
void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
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

    cout << RMax(first);

    return 0;
}