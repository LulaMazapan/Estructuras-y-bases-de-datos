#include <iostream>
#include <math.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class SAT
{

	float A;

public:
	SAT() { A = 0.25; }

	void satura();
};

void SAT::satura()
{
	int i, j;

	for (i = 0;; i++)
	{
		for (j = 0; j <= 13; j++)
		{
			A = (pow(2, i) * pow(2, j)) + A;

			printf("A= %g\t\t %f\n", A, A);
		}
	}
}

int main()
{

	SAT R;

	R.satura();
	getch();

	return 0;
}
