#include<iostream>
#include<fstream>
#include<windows.h>
#include<string.h>
#include<vector>
#include<conio.h>
#include<stdlib.h>
#include<cstdlib>
#include"validaciones.hpp"

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

//estructura de usuarios

struct loggin{
	char usuario[20];
	int contrasena;
};

int main(int argc, char* argv[])
{
    //declarando las variables de los usuario del tipo loggin
	loggin usuarioAdmin;
	loggin usuarioAtencion;
	loggin usuarioCocina;
	loggin usuarioCaja;

	//definir vectores de usuario y clave
	vector<string> usuarios;
	vector<int> claves;

	//añadir usuarios al vector 
	usuarios.push_back(usuarioAdmin.usuario);

	//añadir claves al vector 
	claves.push_back(usuarioAdmin.contrasena);

	usuarioAdmin.contrasena = 1234;
	strcpy_s(usuarioAdmin.usuario, "admin");

	ofstream f("datos.bin", ios::binary);
	if (f.is_open())
	{
		f.write((char*)&usuarioAdmin, sizeof(loggin));
	}
	else
	{
		cout << "Error de apertura de archivo." << endl;
	}
	f.close();

    ifstream lectura("datos.bin", ios::binary);
	lectura.read((char*)&usuarioAdmin, sizeof(loggin));
	while (!lectura.eof())
	{
		cout << endl << usuarioAdmin.usuario << " " << usuarioAdmin.contrasena;
		lectura.read((char*)&usuarioAdmin, sizeof(loggin));
	}
	lectura.close();

	// Leo el registro 42 (creo que es Arthur Dent).
	/*ifstream agendita("agenda.txt", ios::binary);
	agendita.seekg(1 * sizeof(loggin));
	agendita.read(reinterpret_cast<char *>(&usuarioAdmin), sizeof(loggin));*/

	//loguearse para acceder al sistema
	char user[20];
	string password;
	int num;

	/*cout <<endl<<"Ingrese su usuario: "; cin >> user;
	cout << "Ingrese su contrasena: "; cin >> password;*()
	

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
	}*/
	int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        cin>>user;
	
        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuarioAdmin.usuario && claves[i] == usuarioAdmin.contrasena)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        /* 
        Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
        */
    }

    cin.get();

return 0;
}