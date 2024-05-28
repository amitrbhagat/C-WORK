#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void remove(Node *p)
{
    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
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
    Node *fifth = NULL;

    first = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    fifth = new Node();

    first->data = 7;
    first->next = second;

    second->data = 10;
    second->next = third;

    third->data = 10;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = fifth;

    fifth->data = 20;
    fifth->next = NULL;

    remove(first);
    cout<<"after removing duplicates"<<endl;
    display(first);
    return 0;
}