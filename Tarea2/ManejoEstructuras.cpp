#include <iostream>

using namespace std;

struct Perro{

    char Nombre[30];
    string Raza;
    int Edad;
    float Peso;
};

int main(){

    Perro A = {"Blanca","Caniche",9,10};

    Perro B;

    Perro C;

    Perro *p;

    Perro *q;

    cout<<"Tamnio estructura: "<<sizeof(A)<<" bytes.\t"<<"Tamanio apuntador: "<<sizeof(p)<<" bytes."<<endl;

//Datos en la declaración de la variable.

    cout<<"Datos en la declaracion de la variable."<<endl;
    cout<<A.Nombre<<"\t"<<A.Raza<<"\t"<<A.Edad<<" anios "<<A.Peso<<" kilos"<<endl;

//Datos accesando a ellos.

    cout<<endl<<"Datos accesando a ellos."<<endl;

    cout<<"Dame el nombre de la mascota: ";
    cin>>B.Nombre;

    cout<<"Dame la raza del perro: ";
    cin>>B.Raza;

    cout<<"Dame la edad del perro: ";
    cin>>B.Edad;

    cout<<"Dame el peso del perro: ";
    cin>>B.Peso;

    cout<<B.Nombre<<"\t"<<B.Raza<<"\t"<<B.Edad<<" anios "<<B.Peso<<" kilos"<<endl;

    //Apuntador manipula la estructura.

    p = &C;

    cout<<endl<<"Apuntador manipula la estructura."<<endl;

    cout<<"Dame el nombre de la mascota: ";
    cin>>p->Nombre;

    cout<<"Dame la raza del perro: ";
    cin>>p->Raza;

    cout<<"Dame la edad del perro: ";
    cin>>p->Edad;

    cout<<"Dame el peso del perro: ";
    cin>>p->Peso;

    cout<<p->Nombre<<"\t"<<p->Raza<<"\t"<<p->Edad<<" anios "<<p->Peso<<" kilos"<<endl;

    //Apuntador se comporta como la estructura.

    q = new Perro;

    cout<<endl<<"Apuntador se comporta como la estructura."<<endl;

    cout<<"Dame el nombre de la mascota: ";
    cin>>q->Nombre;

    cout<<"Dame la raza del perro: ";
    cin>>q->Raza;

    cout<<"Dame la edad del perro: ";
    cin>>q->Edad;

    cout<<"Dame el peso del perro: ";
    cin>>q->Peso;

    cout<<q->Nombre<<"\t"<<q->Raza<<"\t"<<q->Edad<<" anios "<<q->Peso<<" kilos"<<endl;

    system("pause");
    
}