#ifdef LOGGIN_H_INCLUDED
#define LOGGIN_H_INCLUDED
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include "SimonCodigo.h"
#include "Andre.h"
#include "Angel.h"
#include "Santiago.h"
#include "Loggin.h"


using namespace std;

int ingresar(bool ingreso, int contadorIntentos)
{
	while(ingreso == false && contadorIntentos < 3)
	{
		fflush(stdin);
		cout << endl <<"\t USUARIO: "; getline(cin, user);
		cout << endl <<"\t CONTRASENA: "; cin >> password;
		
		if (user == usuarioAdmin.usuario && password == usuarioAdmin.contrasena)
		{
			//ingreso = true;
			system("cls");
			programaAdmin();
		}
		//ingreso atencion
		else if (user == usuarioAtencion.usuario && password == usuarioAtencion.contrasena)
		{
			//ingreso = true;
			system("cls");
			atencion();
		}
		else
		{
			contadorIntentos++;
			if(contadorIntentos == 3)
			{
				cout<<"\n\t No pudo ingresar. ADIOS.";
				exit(10);
			}
			cout << "\n \t\t El usuario o contrase?a son incorrectos, le quedan " << 3-contadorIntentos << " intentos \n";
		}
	}
}
#endif
