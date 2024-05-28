#include <iostream>
#include "hashtable.h"
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void sortinsert(node **H, int x)
{
    node *t, *q = NULL, *p = *H;
    t = new node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = p;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

node *search(node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int hashtable(int key)
{
    return key % 10;
}

void insert(node *h[], int key)
{
    int index = hashtable(key);
    sortinsert(&h[index], key);
}

int main()
{
    node *ht[10];
    int i;
    for (i = 0; i < 10; i++)
        ht[i] = NULL;

    insert(ht, 75);
    insert(ht, 22);
    insert(ht, 42);
    insert(ht, 99);
    for (i = 0; i < 10; i++)
    {
        cout << ht[i] << " ";
    }

    cout << endl;
    node *tmp;
    tmp = search(ht[hashtable(22)], 22);
    cout << tmp->data << " ";
    tmp = search(ht[hashtable(75)], 75);
    cout << tmp->data;

    return 0;
}