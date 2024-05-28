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
    if (p == 0)
        return 0;
    else
        return count(p->next) + 1;
}

int count1(Node *p)
{
    if (p != NULL)
        return 1 + count(p->next);
    else
        return 0;
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

    cout << "total counts are :" << count(first);
    cout << endl;
    cout << "total counts are " << count1(first);
    return 0;
}
