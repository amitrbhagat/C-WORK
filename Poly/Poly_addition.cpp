#include <iostream>
using namespace std;

class Term
{
public:
    int coeff;
    int exp;
};
class poly
{
public:
    int n;
    Term *t;
};

void create(poly *p)
{
    p->t = new Term;
    int i;
    cout << "enter total elements" << endl;
    cin >> p->n;
    cout << "enter elments" << endl;
    for (i = 0; i < p->n; i++)
        cin >> p->t[i].coeff >> p->t[i].exp;
}

poly *add(poly *p1, poly *p2)
{
    int i, j, k;
    i = j = k = 0;
    poly *sum;
    sum = new poly;
    sum->t = new Term[p1->n + p2->n];
    while (i < p1->n && j < p2->n)
    {
        if (p1->t[i].exp > p2->t[j].exp)
            sum->t[k++] = p1->t[i++];
        else if (p1->t[i].exp < p2->t[j].exp)
            sum->t[k++] = p2->t[j++];
        else
        {
            sum->t[k].exp = p1->t[i].exp;
            sum->t[k++].coeff = p1->t[i++].coeff + p2->t[j++].coeff;
        }
    }
    for (; i < p1->n; i++)
        sum->t[k++] = p1->t[i];
    for (; j < p2->n; j++)
        sum->t[k++] = p2->t[j];
    sum->n = k;
    return sum;
}

void display(poly *p)
{
    int i;
    for (i = 0; i < p->n; i++)
        cout << p->t[i].coeff << " X " << p->t[i].exp << " + ";
    cout << "\n";
}

int main()
{
    poly p1, p2, *p3;
    create(&p1);
    create(&p2);
    p3 = add(&p1, &p2);

    cout << "\n";
    display(&p1);
    cout << "\n";
    display(&p2);
    cout << "\n";
    display(p3);

    return 0;
}