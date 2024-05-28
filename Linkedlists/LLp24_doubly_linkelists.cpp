#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *Head = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
}

void insert(Node *p, int pos)
{
    Node *t = new Node;
    t->next = t;
    t->data = 200;
    if (pos == 0)
    {
        if (Head == NULL)
        {
            Head = t;
            t->next = Head;
        }
        else
        {
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

void Delete(Node *p, int pos)
{
    Node *r;
    if (pos == 0)
    {
        while (p->next != Head)
            p = p->next;
        if (Head == p)
        {
            delete Head;
        }
        else
        {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        r = p->next;
        p->next = r->next;
        r->next = NULL;
        delete r;
    }
}

int main()
{
    int n = 6;
    int A[n] = {28, 45, 36, 89, 22, 55};
    create(A, n);
    // insert(Head, 4);
    Delete(Head, 5);
    display(Head);
    return 0;
}