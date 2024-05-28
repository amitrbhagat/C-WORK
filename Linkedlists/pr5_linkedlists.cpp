#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    t->next = first->next->next;
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void k(Node *p)
{
    Node *q = first;
    int length = 0;
    while (q)
    {
        length++;
        q = q->next;
    }
    int pos = 4;
    for (int i = 0; i < length - pos; i++)
    {
        p = p->next;
    }
    cout << p->data;
}

void k2(Node *p)
{
    Node *q = first;
    int pos = 5;
    for (int i = 0; i < pos; i++)
    {
        q = q->next;
    }
    while (q)
    {
        p = p->next;
        q = q->next;
    }
    cout << p->data;
}

int is_loop(Node *p)
{
    Node *q = first;
    while (p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
            return 1;
    }
    return 0;
}

Node *start(Node *p)
{
    Node *q = first;
    int loopexists = 0;
    while (p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
        {
            loopexists = 1;
            break;
        }
    }
    if (loopexists)
    {
        p = first;
        while (p != q)
        {
            p = p->next;
            q = q->next;
        }
        return p;
    }
    return NULL;
}

int length(Node *p)
{
    Node *q = first;
    int loopexists = 0;
    while (p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
        if (p == q)
        {
            loopexists = 1;
            break;
        }
    }
    if (loopexists)
    {
        int counter = 0;
        while (p->next != q)
        {
            p = p->next;
            counter++;
        }
        return counter;
    }
    return 0;
}

int main()
{
    int n = 7;
    int A[n] = {58, 77, 98, 167, 228, 388, 444};
    create(A, n);
    // k(first);
    // k2(first);
    // cout << is_loop(first) << endl;
    // if (is_loop(first))
    // {
    //     cout << "snail";
    // }
    // else
    // {
    //     cout << "snake";
    // }
    // cout << start(first);
    cout << length(first);
    return 0;
}