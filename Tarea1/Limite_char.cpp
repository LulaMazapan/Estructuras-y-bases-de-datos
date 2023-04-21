#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

class SAT{

char A;

public:

SAT(){A=5;}

void satura(){

    int num;

    int n = 0;

    for( ; ;){

    A++;

    num = A;
    n++;

    cout<<"A: "<<num<<endl;
    //cout<<"Contador: "<<n<<endl;

    system("pause");

    }
}

};

int main(){

SAT R;

R.satura();

getch();

return 0;

}
