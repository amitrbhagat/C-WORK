#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
} *first = NULL, *Head;

void create(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
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

void insert(Node *p, int pos, int x)
{
    Node *t = new Node;
    t->data = x;
    t->next = t->prev = NULL;
    if (pos == 0)
    {
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        int i;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        if (p->next != NULL)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

void Delete(Node *p, int pos)
{
    int x;
    Node *q = NULL;
    if (pos == 0)
    {
        first = first->next;
        p->next = NULL;
        first->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        int i;
        for (i = 0; i < pos; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if (p->next != NULL)
        {
            p->next->prev = q;
        }
        x = p->data;
        delete p;
    }
}

void Reverse(Node *p)
{
    Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
            first = p;
    }
}

void create2(int B[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = B[0];
    Head->next = Head;
    Head->prev = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = B[i];
        t->prev = last;
        last->next = t;
        t->next = Head;
        Head->prev = t;
        last = t;
    }
}

void Display(Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
}

void Insert(Node *p, int pos, int x)
{
    Node *t = new Node;
    t->data = x;
    t->prev = t;
    t->next = t;
    if (pos == 0)
    {
        while (p->next != Head)
        {
            p = p->next;
        }
        t->next = Head;
        Head->prev = t;
        p->next = t;
        t->prev = p;
        Head = t;
    }
    else
    {
        int i;
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->next->prev = t;
        t->next = p->next;
        p->next = t;
        t->prev = p;
    }
}

int main()
{
    // int n = 6;
    // int A[n] = {5, 6, 7, 8, 9, 10};
    // create(A, n);
    // cout << length(first);
    // insert(first, 5, 100);
    // Delete(first, 5);
    // Reverse(first);
    // display(first);
    int n = 6;
    int B[n] = {5, 6, 7, 8, 9, 10};
    create2(B, n);
    Insert(Head, 5, 100);
    Display(Head);
    return 0;
}