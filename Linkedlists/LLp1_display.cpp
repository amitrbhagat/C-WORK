#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void display(Node *p)
{
    while (p != 0)
    {
        cout << "the elements are " << p->data << endl;
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

    display(first);

    return 0;
}