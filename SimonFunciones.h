#ifndef TOMAPEDIDOS_H_INCLUDED
#define TOMAPEDIDOS_H_INCLUDED
#include <iostream>
using namespace std; 
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

void eliminarDuplicados(int pedido[], int i, int j, int contador)
{
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
}

void distinguirTiempos(int pedido[], int tiempos[], int i, int contador)
{
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
}

void distinguirPlatos(int pedido[], string platos[], int i, int contador)
{
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
			platos[i] = "Dieta";
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
}

void escribirPedido(int pedido[], string platos[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke )
{
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
}

void mayorValorArreglo(int contador, int tiempos[], int& tiempoMax)
{
	for(int i = 0; i < contador; i++)
	{
		if(tiempos[i] > tiempoMax && tiempos[i] != 0)
		{
			tiempoMax = tiempos[i];
		}
	}
}

void asignarMesas(int mesas[], int mesasOcupadas[], int cantidad, int &mesaSeleccionada, bool val = false)
{
	//ingresa datos
	cout<<"Ingrese la cantidad de comensales: ";
	cin>>cantidad;
	while(cantidad < 1 || cantidad > 6)
	{
		cout<<"Ingrese una cantidad valida de usuarios: ";
		cin>>cantidad;
	}
	//muestra mesas disponibles
	for(int i = 0; i < 10; i++)
	{
		if(mesasOcupadas[i] == 1 && cantidad <= mesas[i])
		{
			cout<<"La mesa " <<i+1 <<" esta disponible con " <<mesas[i] <<" espacios."<<endl;
		}
	}
	cout<<"Seleccione una mesa disponible: ";
	cin>>mesaSeleccionada;
	if(mesasOcupadas[mesaSeleccionada-1] == 0)
	{
		cout<<"Esa mesa esta ocupada, porfavor seleccione otra: " <<endl;
		cin>>mesaSeleccionada;
	}
	
	int j = 0;
	//la mesa seleccionada en el arreglo de mesasOcupadas se vuelve 0
	while(val == false && j < 10)
	{
		if(mesaSeleccionada == j + 1)
		{
			val = true;
			mesasOcupadas[j] = 0;
		}
		j++;
	}
	val = false;
	system("pause");
	system("CLS");
}


#endif
