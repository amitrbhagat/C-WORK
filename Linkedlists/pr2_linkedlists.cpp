#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = first->prev = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

int length(Node *p)
{
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void insert(Node *p, int pos)
{
    Node *t = new Node;
    t->data = 100;
    t->next = t->prev = NULL;
    p = first;
    if (pos == 0)
    {
        t->next = p;
        p->prev = t;
        first = t;
    }
    else if (pos > 0 && pos <= length(p))
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        if (p->next != NULL)
        {
            t->next = p->next;
            p->next->prev = t;
            t->prev = p;
            p->next = t;
        }
        else
        {
            t->next = p->next;
            t->prev = p;
            p->next = t;
        }
    }
    else
        cout << "invalid position";
}

void Delete(Node *p, int pos)
{
    Node *q = NULL;

    if (pos == 0)
    {
        p->next->prev = NULL;
        p->next = NULL;
    }
    else if (pos > 0 && pos < length(p))
    {
        for (int i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        if (p->next == NULL)
        {
            p->prev = NULL;
            q->next = NULL;
            delete p;
        }
        else
        {
            p->next->prev = q;
            q->next = p->next;
            p->next = p->prev = NULL;
            delete p;
        }
    }
    else
        cout << "invalid position";
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
    int n = 6;
    int A[n] = {1, 2, 3, 4, 5, 6};
    create(A, n);
    // cout << length(first);
    // insert(first, 6);
    Delete(first, 4);
    display(first);
    return 0;
}