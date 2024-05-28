#include <iostream>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
}

int Count(Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int Sum(Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

void Rdisplay(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        Rdisplay(p->next);
    }
}

int Max(Node *p)
{
    int max = first->data;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

Node *search(Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return 0;
}

void insert(Node *p, int pos)
{
    int i;
    Node *t = new Node;
    t->data = 44;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else if (pos >= 0 && pos <= Count(p))
    {
        if (pos == 0)
        {
            t->next = first;
            first = t;
        }
        else
        {
            for (i = 0; i < pos - 1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
    }
    else
        cout << "invalid position"
             << "\n";
}

void sortinsert(Node *p, int x)
{
    Node *t = new Node;
    Node *q = NULL;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
        first = t;

    else
    {
        while (p != 0 && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void Delete(Node *p, int pos)
{
    int i, x;
    Node *q;
    if (pos == 0)
    {
        p = first;
        first = first->next;
        p->next = NULL;
        x = p->data;
        delete p;
    }
    else if (pos > 0 && pos < Count(p))
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        q->next = NULL;
        x = q->data;
        delete q;
    }
    else
        cout << "invalid position";
}

void Duplicate(Node *p)
{
    Node *q, *r;
    while (p->next != NULL)
    {
        r = p;
        q = p->next;
        while (p->data != q->data && q->next != NULL)
        {
            r = q;
            q = q->next;
        }

        if (p->data == q->data)
        {
            r->next = q->next;
            q->next = NULL;
            delete q;
            q = r;
        }
        p = p->next;
    }
}

void Reverse(Node *p)
{
    Node *q, *r;
    q = p->next;
    r = q->next;
    p->next = NULL;
    while (q->next != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    first = q;
}

int middle(Node *p)
{
    Node *q = p->next;
    while (p && q && q->next)
    {
        p = p->next;
        q = q->next->next;
    }
    return p->data;
}

void print(Node *p)
{
    if (!p)
        return;

    print(p->next);
    cout << p->data << " ";
}

// void create2(int B[], int n)
// {
//     int i;
//     Node *t, *last;
//     second = new Node();
//     second->data = B[0];
//     second->next = NULL;
//     last = second;
//     for (i = 1; i < n; i++)
//     {
//         t = new Node;
//         t->data = B[i];
//         t->next = NULL;
//         last->next = t;
//         last = t;
//     }
// }

// void Merge(Node *p, Node *q)
// {
//     Node *last;
//     if (p->data < q->data)
//     {
//         third = last = p;
//         p = p->next;
//         third->next = NULL;
//     }
//     else
//     {
//         third = last = q;
//         q = q->next;
//         third->next = NULL;
//     }
//     while (p != NULL && q != NULL)
//     {
//         if (p->data < q->data)
//         {
//             last->next = p;
//             last = p;
//             p = p->next;
//             last->next = NULL;
//         }
//         else
//         {
//             last->next = q;
//             last = q;
//             q = q->next;
//             last->next = NULL;
//         }
//     }
//     if (p != NULL)
//         last->next = p;
//     if (q != NULL)
//         last->next = q;
// }

int main()
{
    int n = 7;
    int A[n] = {58, 77, 98, 167, 228, 388, 444};
    create(A, n);

    // Rdisplay(first);
    // cout << Count(first);
    // cout << Sum(first);
    // cout << Max(first);
    // cout << search(first, 15);
    // insert(first, 0);
    // sortinsert(first, 444);
    // Delete(first, 4);
    // Duplicate(first);
    // Reverse(first);
    // Middle(first);
    // display(first);
    // cout << middle(first);
    print(first);

    /*-----------------------------Merge of two linkedlists-----------------------------*/
    // int m = 6;
    // int B[m] = {54, 78, 99, 332, 364, 500};
    // create2(B, m);
    // Merge(first, second);
    // display(third);
    return 0;
}