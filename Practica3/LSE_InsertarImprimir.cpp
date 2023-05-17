#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//

char Cerrar();

struct info{
	
	char Nom[30];
	int Edad;
	float Peso;
	double Alt;
	
};

info ini = {"\0",0,0,0};

info Leer()
{
	info R;
	
	cout<<"Dame el Nombre: ";
	fflush(stdin);
	cin.getline(R.Nom,30);
	
	cout<<"Dame la Edad: ";
	cin>>R.Edad;
	
	cout<<"Dame el Peso: ";
	cin>>R.Peso;
	
	cout<<"Dame la Altura: ";
	cin>>R.Alt;

	return R;
}

//

class Nodo{
	
	info Datos;
	Nodo *Sig;
	
	public:
	
	Nodo(info D = ini, Nodo *S = NULL)
	{
		Datos = D;
		Sig = S;
	}
	
	void ModDatos(info D){Datos = D;}
	
	void  ModEdad(int e){Datos.Edad = e;}
	
	void ModSig(Nodo *s){Sig = s;}
	
	info RegDatos(){return(Datos);}
	
	Nodo *RegSig(){return(Sig);}
	
	char *RegNom(){return(Datos.Nom);}
	
	int RegEdad(){return(Datos.Edad);}
	
	float RegPeso(){return(Datos.Peso);}
	
	double RegAlt(){return(Datos.Alt);}
	
	void ImprimeDatos();
	
};

void Nodo::ImprimeDatos(){
	
	cout<<"Nombre: "<<Datos.Nom<<endl;
	cout<<"Edad: "<<Datos.Edad<<endl;
	cout<<"Peso: "<<Datos.Peso<<endl;
	cout<<"Altura: "<<Datos.Alt<<endl;
}

//

class LSE{

  Nodo *st, *ed, *gen;
  
  public:
  	
  LSE()
  {
  	st = ed = gen = NULL;
  }
  
  void Seguridad();
  void Insertar(info X);
  void Imprimir();
  
};

void LSE::Seguridad()
{
	if(gen == NULL){
			
			cout<<"No hay memoria.";
			exit(-1);
			
		}
}

void LSE::Insertar(info X)
{
	if(st == NULL){
		
		gen = new Nodo(X);
		
		//
		
		Seguridad();
		
		st = gen;
	}
	else{
		
		Nodo *piv = gen;
		
		gen = new Nodo(X);
		
		//
		
		Seguridad();
		
		piv -> ModSig(gen);
		
		ed = gen;
	
	}
}

void LSE::Imprimir(){
	
	for(Nodo *i = st ; i != NULL ; i = i->RegSig()){
		
		cout<<"\t"<<i->RegNom()<<endl;
		cout<<"\t"<<i->RegEdad()<<endl;
		cout<<"\t"<<i->RegPeso()<<endl;
		cout<<"\t"<<i->RegAlt()<<endl;
		
		cout<<endl;
		
		cout<<endl;
		
	}
}

char Cerrar(){
	
	char opc;
	
	do{
		
		
		cout<<"Desea salir del programa? (Y/N)....... "<<endl;
	    cin>>opc;
	    	
			if(toupper(opc) == 'Y')
		 	{
				exit(0);
			}
			if (toupper(opc) != 'N')
			{
				cout<<"Escriba y o n."<<endl;
				system("pause");
				system("cls");
			}
			
	}while(toupper(opc) != 'N');
	
	return toupper(opc);
}

//

int main()
{	
	LSE lista;
	info persona = {"\0", 0, 0, 0};

	int num;
	char opc[5];
	char salir;
	
	do{
		
	   system("cls");
	   
	   cout<<"Menu"<<endl<<"--------------------------------"<<endl;
	   cout<<"1) Insertar."<<endl;
	   cout<<"2) Imprimir."<<endl;
	   cout<<"Elige una opcion...... ";
	   fflush(stdin);
	   cin.getline(opc,5);
	   num = atoi(opc);
	
	   switch(num){
	
 	     case 1:
		 system("cls");
		 
		 persona = Leer();
		 
		 lista.Insertar(persona);
		 
		 salir = Cerrar();
	     
	     system("pause");
	   	 break;
		
		 case 2:
		 system("cls");
	    
	     lista.Imprimir();
	     
	     salir = Cerrar();
	     
	     system("pause");
	     break;
	
       	default:
	    
     	cout<<endl<<"Elige una opcion entre el uno y el dos."<<endl;
     	system("pause");
    	break;
    	
    	}
    	
	}while(salir != 'Y');

}
