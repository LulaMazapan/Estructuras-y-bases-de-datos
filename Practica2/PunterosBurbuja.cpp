#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int *Aux;
    int *p[5];
    int A[5];
    A[0] = 8;
    A[1] = 5;
    A[2] = 7;
    A[3] = 3;
    A[4] = 9;

    for (i = 0; i < 5; i++)
    {
        p[i] = &A[i];
    }

    for (i = 0; i < 5; i++)
    {

        for (j = 0; j < 4; j++)
        {
            if (*p[j] > *p[j + 1])
            {
                Aux = p[j];

                p[j] = p[j + 1];

                p[j + 1] = Aux;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        cout << p[i] << "\t" << *p[i] << "\t" << &A[i] << "\t" << A[i] << "\t" << endl;
    }

    return 0;
}
