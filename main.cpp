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

loggin usuarioAdmin;
loggin usuarioAtencion;
loggin usuarioCocina;
loggin usuarioCaja;

int mesasSeleccionada = 0;

//modificarLoggin();
int programaMenu();
int programaMesas();
int tomaPedidos();

int main()
{
    //declarando las variables de los usuario del tipo loggin
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

    ifstream lectura("datos.txt", ios::binary | ios::app);
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
		//ingreso atencion
		else if (user == usuarioAtencion.usuario && password == usuarioAtencion.contrasena)
		{
			ingreso = true;
			system("cls");
			programaMesas();
			//system("cls");
			
			
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
			cout << "\n \t\t El usuario o contraseña son incorrectos, le quedan " << 3-contadorIntentos << " intentos \n";
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
			ofstream f("datos.bin", ios::binary | ios::app);
			
			f.write((char*)&usuarioAdmin, sizeof(loggin));
			f.close();
		}
		break;
	}

return 0;
}

void modificarLoggin(ifstream &lectura)
{
	string userAux, passwordAux;
	lectura.open("datos.txt", ios::binary | ios::in);
	ofstream aux("auxiliar.txt", ios::binary | ios::out);
	if(lectura.is_open())
	{
		cout<<"Dijite el usuario "; cin >> usuarioAdmin.usuario;
		lectura>>userAux; 
		while(!lectura.eof())
		{
			lectura>>usuarioAdmin.usuario; 
			if(usuarioAdmin.usuario == userAux)
			lectura>>usuarioAdmin.contrasena;
		}
	}
}

int programaMenu()
{
	string bebida1 = "Emoliente";
	string bebida2 = "Chicha";
	string entradas1 = "Ensalada fresca";
	string entradas2 = "Papa a la huancaina";
	string segundo1 = "Fideos verdes";
	string segundo2 = "Arroz chaufa";
	string segundo3 = "Arroz con pollo";
	string segundo4 = "Dieta de pollo";
	string postre1 = "Torta de chocolate";
	string postre2 = "Keke de zanahoria";
	
	cout<<"Menu:"<<endl;
	cout<<"Bebidas:" <<endl <<"1) "<<bebida1 <<endl <<"2) "<<bebida2 <<endl;
	cout<<"Entradas:" <<endl <<"3) "<<entradas1 <<endl <<"4) "<<entradas2<<endl;
	cout<<"Segundo:" <<endl <<"5) "<<segundo1 <<endl <<"6) "<<segundo2<<endl <<"7) "<<segundo3 <<endl <<"8) "<<segundo4 <<endl;
	cout<<"Postre:" <<endl <<"9) "<<postre1 <<endl <<"10) "<<postre2<<endl;
	
	return 0;
}

int programaMesas()
{
	int mesas[10] = {2, 3, 4, 5, 6, 5, 6, 5, 4, 3};
	int mesasOcupadas[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	
	int cantidad;
	int &mesaSeleccionada = mesasSeleccionada;
	bool val = false;
	int i = 0;
	while(i < 10)
	{
		cout<<"Ingrese la cantidad de comensales: ";
		cin>>cantidad;
		while(cantidad < 1 || cantidad > 7)
		{
			cout<<"Ingrese una cantidad valida de usuarios: ";
			cin>>cantidad;
		}
		
		for(int i = 0; i < 10; i++)
		{
			if(mesasOcupadas[i] == 1 && cantidad <= mesas[i])
			{
				cout<<"La mesa " <<i+1 <<" esta disponible con " <<mesas[i] <<" espacios."<<endl;
			}
		}
		cout<<"Seleccione una mesa disponible: ";
		cin>>mesaSeleccionada;
		while(mesasOcupadas[mesaSeleccionada-1] == 0)
		{
			cout<<"Esa mesa esta ocupada, porfavor seleccione otra: " <<endl;
			cin>>mesaSeleccionada;
		}
		int j = 0;
		while(val == false && j < 10)
		{
			if(mesaSeleccionada == j + 1)
			{
				val = true;
				mesasOcupadas[j] = 0;
			}
			j++;
		}
		system("CLS");
		programaMenu();
		tomaPedidos();
		val = false;
		system("pause");
		system("CLS");
	}
	
	return 0;
}

void leerPedido(int pedido[], bool val, int& i)
{
	while(val == false )
	{
		cin>> pedido[i];
		if(pedido[i] == 0)
		{
			val = true;
		}
		i++;
	}
}

void contarPlatos(int pedido[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke)
{
	for(int i = 0; i < contador; i++)
	{
		if(pedido[i] == 1)
		{
			contadorEmoliente++;
		}
		if(pedido[i] == 2)
		{
			contadorChicha++;
		}
		if(pedido[i] == 3)
		{
			contadorEnsalada++;
		}
		if(pedido[i] == 4)
		{
			contadorPapa++;
		}
		if(pedido[i] == 5)
		{
			contadorFideos++;
		}
		if(pedido[i] == 6)
		{
			contadorArrozChaufa++;
		}
		if(pedido[i] == 7)
		{
			contadorArrozPollo++;
		}
		if(pedido[i] == 8)
		{
			contadorDietaPollo++;
		}
		if(pedido[i] == 9)
		{
			contadorTorta++;
		}
		if(pedido[i] == 10)
		{
			contadorKeke++;
		}
	}
}

int tomaPedidos()
{
	int i = 0;
	int tiempoMax = 0;
	bool val = false;
	int pedido[30] = { };
	int contadorEmoliente = 0;
	int contadorChicha = 0;
	int contadorEnsalada = 0;
	int contadorPapa = 0;	
	int contadorFideos = 0;
	int contadorArrozChaufa = 0;
	int contadorArrozPollo = 0;
	int contadorDietaPollo = 0;
	int contadorTorta = 0;
	int contadorKeke = 0;
	//cout<<"¿Que mesa es?: ";
	//cin>>mesa;
	
	cout<<"Ingrese el numero correspondiente de cada plato o bebida que desee ordenar: "<<endl;
	
	leerPedido(pedido, val, i);
	
	system("CLS");	
	
	int contador = i - 1;
	
	string* platos = new string[contador];
	contarPlatos(pedido, i, contador, contadorEmoliente, contadorChicha, contadorEnsalada, contadorPapa, contadorFideos, contadorArrozChaufa, contadorArrozPollo, contadorDietaPollo, contadorTorta, contadorKeke);

	
	for(int i = 0; i < contador; i++)
	{
		for(int j = 0; j < contador; j++)
		{
			if(i != j)
			{
				if(pedido[i] == pedido[j])
				{
					pedido[j] = 0;
				}
			}
		}
	}
	
	int* tiempos = new int[contador];
	for(int i = 0; i < contador; i++)
	{
		if(pedido[i] == 0)
		{
			tiempos[i] = 0;
		}
		if(pedido[i] == 1)
		{
			tiempos[i] = 1;
		}
		if(pedido[i] == 2)
		{
			tiempos[i] = 1;
		}
		if(pedido[i] == 3)
		{
			tiempos[i] = 3;
		}
		if(pedido[i] == 4)
		{
			tiempos[i] = 3;
		}
		if(pedido[i] == 5)
		{
			tiempos[i] = 10;
		}
		if(pedido[i] == 6)
		{
			tiempos[i] = 12;
		}
		if(pedido[i] == 7)
		{
			tiempos[i] = 14;
		}
		if(pedido[i] == 8)
		{
			tiempos[i] = 7;
		}
		if(pedido[i] == 9)
		{
			tiempos[i] = 3;
		}
		if(pedido[i] == 10)
		{
			tiempos[i] = 3;
		}
		
	}
	
	for(int i = 0; i < contador; i++)
	{
		if(pedido[i] == 1)
		{
			platos[i] = "Emoliente";
		}
		if(pedido[i] == 2)
		{
			platos[i] = "Chicha";
		}
		if(pedido[i] == 3)
		{
			platos[i] = "Ensalada fresca";
		}
		if(pedido[i] == 4)
		{
			platos[i] = "Papa a la huancaina";
		}
		if(pedido[i] == 5)
		{
			platos[i] = "Fideos verdes";
		}
		if(pedido[i] == 6)
		{
			platos[i] = "Arroz chaufa";
		}
		if(pedido[i] == 7)
		{
			platos[i] = "Arroz con pollo";
		}
		if(pedido[i] == 8)
		{
			platos[i] = "Dieta de pollo";
		}
		if(pedido[i] == 9)
		{
			platos[i] = "Torta de chocolate";
		}
		if(pedido[i] == 10)
		{
			platos[i] = "Keke de zanahoria";
		}
		
	}
	cout<<"Ticket cocina:"<<endl;
	cout<<"Mesa: " <<mesasSeleccionada <<endl;
	
	
	for(int i = 0; i < contador; i++)
	{
		
		if(pedido[i] == 1)
		{
			cout<<platos[i] <<" x "<<contadorEmoliente <<endl;
		}
		if(pedido[i] == 2)
		{
			cout<<platos[i] <<" x "<<contadorChicha<<endl;
		}
		if(pedido[i] == 3)
		{
			cout<<platos[i] <<" x "<<contadorEnsalada<<endl;
		}
		if(pedido[i] == 4)
		{
			cout<<platos[i] <<" x "<<contadorPapa<<endl;
		}
		if(pedido[i] == 5)
		{
			cout<<platos[i] <<" x "<<contadorFideos<<endl;
		}
		if(pedido[i] == 6)
		{
			cout<<platos[i] <<" x "<<contadorArrozChaufa<<endl;
		}
		if(pedido[i] == 7)
		{
			cout<<platos[i] <<" x "<<contadorArrozPollo<<endl;
		}
		if(pedido[i] == 8)
		{
			cout<<platos[i] <<" x "<<contadorDietaPollo<<endl;
		}
		if(pedido[i] == 9)
		{
			cout<<platos[i] <<" x "<<contadorTorta<<endl;
		}
		if(pedido[i] == 10)
		{
			cout<<platos[i] <<" x "<<contadorKeke<<endl;
		}
		
	}
	system("pause");
	
	cout<<"El tiempo de espera promedio de su pedido es: " ;
	for(int i = 0; i < contador; i++)
	{
		if(tiempos[i] > tiempoMax && tiempos[i] != 0)
		{
			tiempoMax = tiempos[i];
		}
	}
	for(int i = tiempoMax; i >= -1000; i--)
	{
		cout<<i;
		Sleep(1000);
		system("cls");
		if (i < 0)
			system("color 04");
	}
	
	cout<<tiempoMax << " segundos"<<endl;
	system("pause");
	system("cls");
	
	return 0;
}



