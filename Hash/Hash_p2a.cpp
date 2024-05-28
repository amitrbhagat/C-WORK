#include <iostream>
#include "hashtable.h"
using namespace std;

#define size 10

int hashtable(int key)
{
    return key % size;
}

void insert(int h[], int key)
{
    int index, index1, i = 0;

    index = hashtable(key);
 
    if (h[index] != 0)
    {
        while (1)
        {
            index1 = (index + i) % size;
            if (h[index1] == 0)
            {
                h[index1] = key;
                break;
            }
            i++;
        }
    }
    else
        h[index] = key;
}

int search(int h[], int key)
{
    int index, index1, i = 0;

    index = hashtable(key);

    if (index == key)
        return index + i % size;

    else
    {
        while (1)
        {
            index1 = index + i % size;

            if (h[index1] == key)
            {
                return index1;
            }
            i++;
        }
    }
    return 0;
}

int main()
{
    int ht[10] = {0};
    insert(ht, 12);
    insert(ht, 25);
    insert(ht, 35);
    insert(ht, 22);
    insert(ht, 45);
    int i;
    for (i = 0; i < 10; i++)
        cout << ht[i] << " ";

    cout << "\n"
         << "number found at index "
         << search(ht, 12);

    cout << "\n"
         << "number found at index "
         << search(ht, 35);
    return 0;
}