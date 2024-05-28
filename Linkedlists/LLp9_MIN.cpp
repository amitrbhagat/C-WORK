#include<iostream>
using namespace std;


class Node
{
    int data;
    Node *next;

public:
    void create()
    {
        Node *first, *second, *third, *fourth, *fifth, *sixth;
        first = new Node;
        second = new Node;
        third = new Node;
        fourth = new Node;
        fifth = new Node;
        sixth = new Node;

        first->data = 68;
        first->next = second;
        second->data = 10;
        second->next = third;

        third->data = 12;
        third->next = fourth;

        fourth->data = 55;
        fourth->next = fifth;

        fifth->data = 2;
        fifth->next = sixth;

        sixth->data = 9;
        sixth->next = NULL;
    }

    void Max()
    {
        Node *p;
        int m = 32768;
        while (p != 0)
        {
            if (p->data < m)
                m = p->data;
            p = p->next;
        }
        cout << "the minimum number is :" << m;
    }
};

int main()
{

    Node n;
    n.create();
    n.Max();
    return 0;
}

