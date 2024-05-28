

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *search(Node *p, int key) //Because the return type is Node.So that we can use Node
{

    while (p != 0)
    {
        if (key == p->data)
            return p;

        p = p->next;
    }
    return NULL;
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

    cout << search(first, 15) << endl;
    cout << endl
         << search(first, 25);

    return 0;
}