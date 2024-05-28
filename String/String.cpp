#include <iostream>
using namespace std;

int Length1()
{
    int i, length = 0;
    char A[] = "ABCDEFG";
    for (i = 0; A[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

int Length2()
{
    int i, length = 0;
    char A[] = "ABCDEFG";
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    return i;
}

void Length3()
{
    string txt = "ABCDEFG";
    cout << txt.length();
}

void changecase1() // upper to lower
{
    char A[] = "ABCDE";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    }
    cout << A;
}

void changecase2() // lower to upper
{
    char a[] = "abcde";
    int i;
    for (i = 0; a[i] != '\0'; i++)
    {
        a[i] = a[i] - 32;
    }
    cout << a;
}

void Toggle()
{
    int i;
    char A[] = "AyBCfhM";
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] >= 65 && A[i] <= 90)
        {
            A[i] = A[i] + 32;
        }
        else if (A[i] >= 97 && A[i] <= 122)
        {
            A[i] = A[i] - 32;
        }
    }
    cout << A;
}

void Vowel()
{
    int i, vcount = 0, ccount = 0;
    char A[] = "How Are You";
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' ||
            A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vcount++;
        }
        else if ((A[i] >= 65 && A[i] <= 90) || (A[i] >= 97 && A[i] <= 122))
        {
            ccount++;
        }
    }
    cout << "number of consonents are    " << ccount << "\n";
    cout << "number of vowels are the    " << vcount;
}

int countword()
{
    int i, word = 1;
    char A[] = "How Are   You";
    for (i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == ' ' && A[i - 1] != ' ')
        {
            word++;
        }
    }
    return word;
}

int validate()
{
    char A[] = "Amit?123";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (!(A[i] >= 65 && A[i] <= 90) && !(A[i] >= 97 && A[i] <= 122) && !(A[i] >= 48 && A[i] <= 57))
            return 0;
    }
    return 1;
}

void Reverse1()
{
    int i, j, temp;
    char A[] = "abcdef";
    char B[6];
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; i--, j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << B;
}

void Reverse2()
{
    int i, j, temp;
    char A[] = "abcdef";
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
    cout << A;
}

void compare()
{
    int i, j;
    char A[] = "ABcD";
    char B[] = "ABCD";

    for (i = 0, j = 0; A[i] != '\0' || B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        cout << "Strings are equal";
    else if (A[i] < B[j])
        cout << "String is small";
    else
        cout << "string is greater";
}

void pelindrome() // using 2 Arrays
{
    int i, j, flag = 0;
    char A[] = "MADAM";  
    char B[6];                         //string size more than one,than the another string
    for (i = 0; A[i] != '\0'; i++)
    {
    }
    i = i - 1;
    for (j = 0; i >= 0; j++, i--)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    for (i = 0, j = 0; A[i] != '\0', B[j] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
            flag = 1;
    }
    if (flag == 1)
        cout << "Both Strings are not same";
    else
        cout << "Strings are  same";
}

int pelindrome2() // using 1 Array
{
    int i, j;
    char A[] = "MADAM";
    for (j = 0; A[j] != '\0'; j++)
    {
    }
    j = j - 1;
    for (i = 0; i < j; i++, j--)
    {
        if (A[i] != A[j])
            return 0;
    }
    return 1;
}

void Duplicate()
{
    int i, j;
    string A = "ABCDAFGCDK";
    for (i = 0; A[i] != '\0'; i++)
    {
        for (j = i + 1; A[j] != '\0'; j++)
        {
            if (A[i] == A[j])
                cout << A[j] << " ";
        }
    }
}

void Duplicate2() // USING HASH
{
    int i, H[26] = {0};
    char A[] = "finding";
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << char(i + 97) << " ";
            // cout << i + 97 << " ";
            cout << H[i] << "\n";
        }
    }
}

void Duplicate3()
{
    int i, H[26] = {0};
    char A[] = "FINDING";
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 65]++;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] > 1)
        {
            cout << char(i + 65) << " ";
            // cout << i + 65 << " ";
            cout << H[i] << "\n";
        }
    }
}


void Duplicate4()
{
    int i, H[123] = {0};
    char A[] = "ABdhANd";
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] + 0]++;
    }
    for (i = 0; i < 123; i++)
    {
        if (H[i] > 1)
           // cout << i + 0 << " ";  // PRINT BOTH
        cout << char(i + 0) << " ";
    }
}

void Anagram()
{
    int i, H[26] = {0}, flag = 0;
    char A[] = "MEDICAL";
    char B[] = "DECIMAL";

    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97]++;
    }
    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97]--;
    }
    for (i = 0; i < 26; i++)
    {
        if (H[i] < 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "it is not Anagram";
    }
    else
    {
        cout << "it is an Anagram";
    }
}

int main()
{
    // cout << Length1() << "\n";
    // cout << Length2() << "\n";
    // Length3();
    // changecase();
    // changecase2();
    // Toggle();
    // Vowel();
    // cout << countword();
    // cout << validate();
    // cout << "\n";
    // if (validate())
    // {
    //     cout << "String is validate";
    // }
    // else
    // {
    //     cout << "String is not validate";
    // }
    // Reverse1();
    // Reverse2();
    // compare();
    //pelindrome();
    // cout << pelindrome2();
    // Duplicate();
    // Duplicate2();
    // Duplicate3();
    //Duplicate4();
    Anagram();
    return 0;
}