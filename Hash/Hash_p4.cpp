#include <iostream>
#include "hashtable.h"
using namespace std;

#define size 10
#define PRIME 7 //Last Second PRIME NUMBER

int hashtable_1(int key)
{
    return key % size;
}

int hashtable_2(int key)
{
    return PRIME - (key % PRIME);
}

void insert(int h[], int key)
{
    int index, index1, index2, i = 0;

    index1 = hashtable_1(key);

    if (h[index1] != 0)
    {
        index2 = hashtable_2(key);

        while (1)
        {
            index = (index1 + i * index2) % size;

            if (h[index] == 0)
            {
                h[index] = key;
                break;
            }
            i++;
        }
    }
    else
        h[index1] = key;
}

int search(int h[], int key)
{
    int index, index1, index2, i = 0;

    index1 = hashtable_1(key);

    if (h[index1] != key)
    {
        index2 = hashtable_2(key);
        while (1)
        {
            index = (index1 + i * index2) % size;

            if (h[index] == key)
            {
                return index;
                break;
            }
            i++;
        }
    }
    return (index1) % size;
}

int main()
{
    int ht[10] = {0};
    insert(ht, 5);
    insert(ht, 25);
    insert(ht, 15);
    insert(ht, 35);
    insert(ht, 95);

    int i;
    for (i = 0; i < 10; i++)
        cout << ht[i] << " ";

    cout << "\n"
         << "number found at index "
         << search(ht, 35);

    cout << "\n"
         << "number found at index "
         << search(ht, 95);

    return 0;
}