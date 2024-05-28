#include <iostream>
#include "hashtable.h"
using namespace std;

#define size 10

int hashtable(int key)
{
    return key % size;
}

int probe(int h[], int key)
{
    int index = hashtable(key);
    int i = 0;
    while (h[(index + i * i) % size] != 0)
        i++;
    return (index + i * i) % size;
}

void insert(int h[], int key)
{
    int index = hashtable(key);

    if (h[index] != 0)
        index = probe(h, key);
    h[index] = key;
}

int search(int h[], int key)
{
    int index = hashtable(key);
    int i = 0;
    while (h[(index + i * i) % size] != key)
        i++;
    return (index + i * i) % size;
}

int main()
{

    int ht[10] = {0};
    insert(ht, 20);
    insert(ht, 21);
    insert(ht, 23);
    insert(ht, 43);
    insert(ht, 13);
    insert(ht, 27);

    int i;
    for (i = 0; i < 10; i++)
        cout << ht[i] << " ";

    cout << "\n"
         << " number found at index " << search(ht, 13);
    return 0;
}