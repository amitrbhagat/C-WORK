#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class Sparse
{
public:
    int m, n, num;
    Element *e;
};

void create(Sparse *s)
{
    int i;
    s->e = new Element[s->num];
    cout << "Enter Dimension"
         << " ";
    cin >> s->m >> s->n;
    cout << "Enter total number"
         << " ";
    cin >> s->num;
    cout << "enter the non zero elements"
         << "\n";
    for (i = 0; i < s->num; i++)
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
}

Sparse *Add(Sparse *s1, Sparse *s2)
{
    int i, j, k;
    i = j = k = 0;

    Sparse *sum = new Sparse;
    sum->m = s1->m;
    sum->n = s1->n;

    if (s1->m != s2->m && s1->n != s2->n)
        return NULL;
    sum->e = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k++].x = s1->e[i++].x - s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];

    sum->num = k;
    return sum;
}

void display(Sparse *s)
{
    int i, j, k = 0;
    for (i = 0; i < s->m; i++)
    {
        for (j = 0; j < s->n; j++)
        {
            if (i == s->e[k].i && j == s->e[k].j)
                cout << s->e[k++].x << " ";
            else
                cout << "0"
                     << " ";
        }
        cout << "\n";
    }
}

main()
{
    Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = Add(&s1, &s2);
    cout << "\n";
    display(s3);
    return 0;
}