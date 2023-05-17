// Bibliotecas.

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// Estructura con la información que contendrá cada nodo.

struct info{
	
	char Nom[50];
	int  Cantidad;
    float Precio;

};


info ini = {"\0",0,0}; // Inicialización de parámetros.

info Leer() // Función para leer datos.

{
	info A;
	
	cout<<"Dame el Nombre del medicamento: ";
	cin.getline(A.Nom,50);
	
	cout<<"Cantidad: ";
	cin>>A.Cantidad;
	
	cout<<"Precio: $";
	cin>>A.Precio;
	
	return A;

} 

//clase Nodo.

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
	
	void ModSig(Nodo *s){Sig = s;}
	
	info RegDatos(){return(Datos);}
	
	Nodo *RegSig(){return(Sig);}
	
	char *RegNom(){return(Datos.Nom);}
	
	int RegCantidad(){return(Datos.Cantidad);}
	
	float RegPrecio(){return(Datos.Precio);}
		
};

//Clase Lista Simplemente Enlazada.

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

void LSE::Seguridad() //Función para insertar una medida de seguridad al momento de crear memoria dinámica.
{
	if(gen == NULL){
			
			cout<<"No hay memoria.";
			exit(-1);
			
		}
}

void LSE::Insertar(info X) //Función para insertar nodos a la lista.
{
	if(st == NULL){ //Si la lista está vacía.
		
		gen = new Nodo(X);
		
		Seguridad(); //Código de Seguridad
		
		st = gen;
	}
	else{ //Si la lista contiene nodos.
		
		Nodo *piv = gen;
		
		gen = new Nodo(X);
		
		Seguridad(); //Código de Seguridad
		
		piv -> ModSig(gen);
		
		ed = gen;
	
	}
}

void LSE::Imprimir(){ //Función para Imprimir los datos almacenados en la lista.
	
	for(Nodo *i = st ; i != NULL ; i = i->RegSig()){
		
		cout<<"Nombre del producto: "<<i->RegNom()<<endl;
		cout<<"Cantidad disponible: "<<i->RegCantidad()<<endl;
		cout<<"Precio por unidad: $"<<i->RegPrecio()<<endl;
        
		cout<<endl;
		
	}
}

//

char Cerrar(){ //Función para preguntar al usuario si desea continuar utilizando el programa o salir.
	
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
	LSE lista; //Objeto de LSE.

    info Medicamento = ini; //Declaración de estructura que contendrá el nodo e inicialización de parámetros.

	int num; //Variable parte del menú.
	char opc[5];//Variable parte del menú.
	char salir;//Variable que controla la repetición del menú.
	
	do{
		
	   system("cls");
	   
	   cout<<"Menu"<<endl<<"--------------------------------"<<endl;
	   cout<<"1) Insertar."<<endl;
	   cout<<"2) Imprimir."<<endl;
	   cout<<"Elige una opcion...... ";

       //Selección de opción.
	   fflush(stdin);
	   cin.getline(opc,5);
	   num = atoi(opc);
	
       //Opciones disponibles.
       
	   switch(num){
        
        //Insertar.
 	     case 1:

		 system("cls");
		 
		 Medicamento = Leer(); //Lectura de datos.
		 
		 lista.Insertar(Medicamento); //Insertar los datos en la LSE.
		 
		 salir = Cerrar(); //Función para salir o continuar en el programa.
	     
	     system("pause");
	   	 break;
		
        //Imprimir.
		 case 2:

		 system("cls");
	    
	     lista.Imprimir(); //Función para imprimir la lista.
	     
	     salir = Cerrar(); //Función para salir o continuar en el programa.
	     
	     system("pause");
	     break;
    
        //Cualquier opción que no se encuentre en el menú.
       	default:
	    
     	cout<<endl<<"Elige una opcion entre el uno y el dos."<<endl;
     	system("pause");
    	break;
    	
    	}
    	
	}while(salir != 'Y'); //Condición de repetición.

}