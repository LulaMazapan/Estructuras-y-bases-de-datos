#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int *Aux;
    int *p[10];
    int A[10] = {5, 8, 2, 4, 1, 9, 3, 7, 6, 10};

    /*
    A[0] = 5;
    A[1] = 8;
    A[2] = 2;
    A[3] = 4;
    A[4] = 1;
    A[5] = 9;
    A[6] = 3;
    A[7] = 7;
    A[8] = 6;
    A[9] = 10;
    */

    for (i = 0; i < 10; i++)
    {
        p[i] = &A[i];
    }

    for (i = 0; i < 10; i++)
    {

        for (j = 0; j < 9; j++)
        {
            if (*p[j] > *p[j + 1])
            {
                Aux = p[j];

                p[j] = p[j + 1];

                p[j + 1] = Aux;
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        cout << p[i] << "\t" << *p[i] << "\t" << &A[i] << "\t" << A[i] << "\t" << endl;
    }

    return 0;
}
