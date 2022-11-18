#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include "SimonCodigo.h"
#include "Andre.h"
#include "Angel.h"

using namespace std;

//estructura de usuarios

struct loggin{
	char usuario[20];
	int contrasena;
};

loggin usuarioAdmin;
loggin usuarioAtencion;
loggin usuarioCocina;
loggin usuarioCaja;

int mesasSeleccionada = 0;


int programaMenu();
int programaMesas();
int tomaPedidos();

int main()
{
	//declarando  valores a las variables de los usuario del tipo loggin
	usuarioAdmin.contrasena = 1234;
	strcpy(usuarioAdmin.usuario, "admin");
	
	usuarioAtencion.contrasena = 1234;
	strcpy(usuarioAtencion.usuario, "atencion");
	
	usuarioCocina.contrasena = 1234;
	strcpy(usuarioCocina.usuario, "cocina");
	
	usuarioCaja.contrasena = 1234;
	strcpy(usuarioCaja.usuario, "caja");
	
	ofstream f("datos.txt", ios::binary | ios::trunc);
	if (f.is_open())
	{
		f.write((char*)&usuarioAdmin, sizeof(loggin));
		f.write((char*)&usuarioAtencion, sizeof(loggin));
		f.write((char*)&usuarioCocina, sizeof(loggin));
		f.write((char*)&usuarioCaja, sizeof(loggin));
	}
	else
	{
		cout << "Error de apertura de archivo." << endl;
	}
	f.close();
	
	ifstream lectura("datos.txt", ios::binary);
	lectura.read((char*)&usuarioAdmin, sizeof(loggin));
	lectura.close();
	
	
	//loguearse para acceder al sistema
	string user;
	int password;
	
	bool ingreso = false; 
	int contadorIntentos = 0;
	
	cout << endl <<"\t\t\t\t SISTEMA DE LOGGIN: ";
	cout << endl <<"\t\t\t\t--------------------";
	
	while(ingreso == false && contadorIntentos < 3)
	{
		cout << endl <<"\t USUARIO: "; getline(cin, user);
		cout << endl <<"\t CONTRASENA: "; cin >> password;
		
		if (user == usuarioAdmin.usuario && password == usuarioAdmin.contrasena)
		{
			ingreso = true;
			system("cls");
			programaAdmin();
		}
		//ingreso atencion
		else if (user == usuarioAtencion.usuario && password == usuarioAtencion.contrasena)
		{
			ingreso = true;
			system("cls");
			atencion();
		}
		//ingreso cocina
		else if (user == usuarioCocina.usuario && password == usuarioCocina.contrasena)
		{
			ingreso = true;
		}
		//ingreso caja
		else if (user == usuarioCaja.usuario && password == usuarioCaja.contrasena)
		{
			ingreso = true;
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
	
	return 0;
}




