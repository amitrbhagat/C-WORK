#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

int Is_sort(Node *p)
{
    int x = -326598;

    while (p != 0)
    {
        if (p->data < x)
            return false;
        x = p->data;
        p = p->next;
    }
    return true;
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

    //cout<<Is_sort(first);
    if (Is_sort(first))
    {
        cout << "It is sorted " << endl;
    }
    else
    {
        cout << "not sorted ";
    }
    return 0;
}