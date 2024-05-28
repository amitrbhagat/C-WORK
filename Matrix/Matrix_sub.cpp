#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class sparse
{
public:
    int m;
    int n;
    int num;
    Element *e;
};

void create(sparse *s)
{
    s->e = new Element;
    cout << "enter the dimension m and n" << endl;
    cin >> s->m >> s->n;
    cout << "enter total non zero elements" << endl;
    cin >> s->num;
    cout << "enter the dimension" << endl;
    for (int i = 0; i < s->num; i++)
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
}

sparse *Sub(sparse *s1, sparse *s2)
{
    int i, j, k;
    i = j = k = 0;
    sparse *sum = new sparse;
    sum->e = new Element[s1->num + s2->num];
    sum->num = k;
    sum->m = s1->m;
    sum->n = s1->n;
    if (s1->m != s2->m && s1->n != s2->n)
        return 0;

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
            if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].x -= s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; j < s2->num; j++)
        sum->e[k++] = s2->e[j];
    return sum;
}

void display(sparse *s)
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
        cout << endl;
    }
}

int main()
{
    sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = Sub(&s1, &s2);

    cout << "first matrix" << endl;
    display(&s1);
    cout << "second matrix" << endl;
    display(&s2);
    cout << "third matrix" << endl;
    display(s3);
    return 0;
}