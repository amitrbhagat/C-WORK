#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

int Delete(Node *p, int pos)
{
    Node *q = NULL;
    int x, i;
    if (pos == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        delete p;
        return x;
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
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

    cout << "the deleted element is:" << Delete(first, 2) << endl;
    cout << endl;
    cout << "after deleting,the remaining elements are" << endl;
    display(first);

    return 0;
}