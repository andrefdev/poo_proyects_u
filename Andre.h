#ifndef ADMINISTRACION_H_INCLUDED
#define ADMINISTRACION_H_INCLUDED
#include <iostream>
#include "Santiago.h"
#include "Angel.h"
using namespace std;

void programaAdmin()
{
	int num;
	int n;
	cout << "1) Ingresos totales" << endl;
	cout << "2) Historial pedidos" << endl;
	cout << "3) Historial boletas" << endl;
	cout << "4) Salir" << endl;
	cin >> num;
	
	switch (num)
	{
	case 1:
		boletaPrincipal();
		cout<<"Retroceder [1]: "; cin>>n;
		if(n=1){
			system("cls");
			programaAdmin();
		}
		else{
			break;
		}
	case 2:
		   escribir_historial();
		   cout<<"Retroceder [1]: "; cin>>n;
		   if(n=1){
			   system("cls");
			   programaAdmin();
		   }
		   else{
			   break;
		   }
	case 3:
			  escribir_boleta();
			  cout<<"Retroceder [1]: "; cin>>n;
			  if(n=1){
				  system("cls");
				  programaAdmin();
			  }
			  else{
				  break;
			  }
	case 4:
				 //DECLARAR FUNCION LOGIN
				 break;
	}
}

#endif
