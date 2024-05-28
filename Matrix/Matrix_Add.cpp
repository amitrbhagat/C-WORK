#include <iostream>
using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};
class Sparse
{
public:
    int m;
    int n;
    int num;
    Element *e;
};
void create(Sparse *s)
{
    int i;
    s->e = new Element[s->num];
    cout << "enter the dimensions ";
    cin >> s->m >> s->n;
    cout << "enter total elements";
    cin >> s->num;

    cout << "Enter non-zero elements";
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
        return 0;

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
                sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i <= s1->num; i++)
        sum->e[k++] = s1->e[i];
    for (; i <= s2->num; i++)
        sum->e[k++] = s2->e[i];
    
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
                cout << s->e[k++].x << "\t";
            else
                cout << "0"
                     << "\t";
        }
        cout << "\n";
    }
}

int main()
{

    Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    s3 = Add(&s1, &s2);

    cout << "first matrix" << endl;
    display(&s1);
    cout << "2nd matrix" << endl;
    display(&s2);
    cout << "3rd matrix" << endl;
    display(s3);
    return 0;
}