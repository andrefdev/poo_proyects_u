#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>

#include"validaciones.hpp"

using namespace std;

//estructura de usuarios

struct loggin{
	char usuario[20];
	int contrasena;
};

int main()
{
    //declarando las variables de los usuario del tipo loggin
	loggin usuarioAdmin;
	loggin usuarioAtencion;
	loggin usuarioCocina;
	loggin usuarioCaja;

	usuarioAdmin.contrasena = 1234;
	strcpy(usuarioAdmin.usuario, "admin");

	usuarioAtencion.contrasena = 1234;
	strcpy(usuarioAtencion.usuario, "atencion");

	usuarioCocina.contrasena = 1234;
	strcpy(usuarioCocina.usuario, "cocina");

	usuarioCaja.contrasena = 1234;
	strcpy(usuarioCaja.usuario, "caja");

	ofstream f("datos.txt", ios::binary | ios::ate);
	if (f.is_open())
	{
		f.write((char*)&usuarioAdmin, sizeof(loggin));
	}
	else
	{
		cout << "Error de apertura de archivo." << endl;
	}
	f.close();

    ifstream lectura("datos.txt", ios::binary);
	lectura.read((char*)&usuarioAdmin, sizeof(loggin));
	while (!lectura.eof())
	{
		cout << endl << usuarioAdmin.usuario << " " << usuarioAdmin.contrasena;
		//cout << endl << usuarioCocina.usuario << " " << usuarioCocina.contrasena;
		lectura.read((char*)&usuarioAdmin, sizeof(loggin));
	}
	lectura.close();


	//loguearse para acceder al sistema
	string user;
	int password;
	int num;

	
	
	bool ingreso = false; 
	int contadorIntentos = 0;
	
	cout << endl <<"\t\t\t\t SISTEMA DE LOGGIN: ";
	cout << endl <<"\t\t\t\t--------------------";
	
	while(ingreso == false && contadorIntentos < 3)
	{
		cout << endl <<"\t USUARIO: "; cin >> user;
		cout << endl <<"\t CONTRASENA: "; cin >> password;
		
		if (user == usuarioAdmin.usuario && password == usuarioAdmin.contrasena)
		{
			ingreso = true;
		}
		else
		{
			cout << "\n \t\t El usuario o contraseña son incorrectos, le quedan " << 3-contadorIntentos << " intentos \n";
			contadorIntentos++;
		}
	}
	
	cout << "1) Mesas" << endl;
	cout << "2) Historial de pedidos" << endl;
	cout << "3) Ingresos totales" << endl;
	cout << "4) Cambiar contrasena" << endl;
	
	cin >> num;
	
	switch (num)
	{
	case 1:
		cout << "Mesas"; 
		break;
	case 2:
		cout << "Historial de pedidos";
		break;
	case 3:
		cout << "Ingresos totales";
		break;
	case 4:
		cout << "Cambiar contrasena "<<endl;
		bool val = false;
		cout << endl << "Para cambiar su contrasena dijite 1: "; cin >> val;
		if (val == true)
		{
			cout << "Dijite el nuevo usuario: ";
			cin >> usuarioAdmin.usuario;
			cout << "Dijite la nueva contrasena: ";
			cin >> usuarioAdmin.contrasena;
			cin.ignore();
			ofstream f("datos.bin", ios::binary | ios::out);
			
			f.write((char*)&usuarioAdmin, sizeof(loggin));
			f.close();
		}
		break;
	}

	/*if (user == usuarioAdmin.usuario && password == usuarioAdmin.contrasena)
	{
		cout << "1) Mensas" << endl;
		cout << "2) Historial de pedidos" << endl;
		cout << "3) Ingresos totales" << endl;
		cout << "4) Cambiar contrasena" << endl;

		cin >> num;

		switch (num)
		{
		case 1:
			cout << "Mesas"; 
			break;
		case 2:
			cout << "Historial de pedidos";
			break;
		case 3:
			cout << "Ingresos totales";
			break;
		case 4:
			cout << "Cambiar contrasena "<<endl;
			bool val = false;
			cout << endl << "Para cambiar su contrasena dijite 1: "; cin >> val;
			if (val == true)
			{
				cout << "Dijite el nuevo usuario: ";
				cin >> usuarioAdmin.usuario;
				cout << "Dijite la nueva contrasena: ";
				cin >> usuarioAdmin.contrasena;
                cin.ignore();
				ofstream f("datos.bin", ios::binary | ios::out);

				f.write((char*)&usuarioAdmin, sizeof(loggin));
				f.close();
			}
			break;
		}
	}
	*/

return 0;
}
