#include <iostream>
#include <cmath>
using namespace std;

class Term
{
public:
    int coeff;
    int expon;
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
    cout << "enter total term" << endl;
    cin >> p->n;
    cout << "enter coeff and exponent" << endl;
    for (i = 0; i < p->n; i++)
        cin >> p->t[i].coeff >> p->t[i].expon;
}

int eval(poly *p, int x)
{
    int i = 0;
    int sum = 0;
    while (i < p->n)
    {
        sum += p->t[i].coeff * pow(x, p->t[i].expon);
        i++;
    }
    return sum;
}

int main()
{
    poly p;
    create(&p);
    cout << eval(&p, 2);
    return 0;
}