#ifndef CODIGO_H_INCLUDED
#define CODIGO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "SimonFunciones.h"
#include <fstream>
#include <ctime>
#include "Angel.h"
#include "Santiago.h"
using namespace std;

void escribirBoletaMesa(int pedido[], string platos[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke);

void atencion()
{
	int mesas[10] = {2, 3, 4, 5, 6, 5, 6, 5, 4, 3};
	int mesasOcupadas[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	
	int cantidad;
	int mesaSeleccionada;
	bool val = false;
	
	
	//for(int i = 0; i < 10; i++)
	//{
		asignarMesas(mesas, mesasOcupadas, cantidad, mesaSeleccionada, val);
		
		i = 0;
		int j = 0;
		int tiempoMax = 0;
		int pedido[30] = { };
		int mesa;
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
		
		cout<<"Ingrese el numero correspondiente de cada plato o bebida que desee ordenar: "<<endl;
		
		leerPedido(pedido, val, i);
		
		system("CLS");	
		
		int contador = i - 1;
		
		string* platos = new string[contador];
		
		contarPlatos(pedido, i, contador, contadorEmoliente, contadorChicha, contadorEnsalada, contadorPapa, contadorFideos, contadorArrozChaufa, contadorArrozPollo, contadorDietaPollo, contadorTorta, contadorKeke);
		
		eliminarDuplicados(pedido, i, j, contador);
		
		int* tiempos = new int[contador];
		distinguirTiempos(pedido, tiempos, i, contador);
		distinguirPlatos(pedido, platos, i, contador);
		
		
		cout<<"Ticket cocina:"<<endl;
		cout<<"Mesa: " <<mesaSeleccionada <<endl;
		
		escribirPedido(pedido, platos, i, contador, contadorEmoliente, contadorChicha, contadorEnsalada, contadorPapa, contadorFideos, contadorArrozChaufa, contadorArrozPollo, contadorDietaPollo, contadorTorta, contadorKeke);
		
		system("pause");
		
		cout<<"El tiempo de espera promedio de su pedido es: " ;
		mayorValorArreglo(contador, tiempos, tiempoMax);
		
		cout<<tiempoMax << " segundos"<<endl;
		system("pause");
		system("cls");
		
		system("pause");
		
		
		
		ofstream fw;
		fw.open("archivoIT.txt", ios::out | ios::app);
		
		if (fw.is_open())
		{
			
			for (int i = 0; i < contador; i++)
			{
				if(pedido[i] == 1)
				{
					fw << platos[i] <<"," <<contadorEmoliente << "\n";
				}
				if(pedido[i] == 2)
				{
					fw << platos[i] <<"," <<contadorChicha << "\n";
				}
				if(pedido[i] == 3)
				{
					fw << platos[i] <<"," <<contadorEnsalada << "\n";
				}
				if(pedido[i] == 4)
				{
					fw << platos[i] <<"," <<contadorPapa << "\n";
				}
				if(pedido[i] == 5)
				{
					fw << platos[i] <<"," <<contadorFideos << "\n";
				}
				if(pedido[i] == 6)
				{
					fw << platos[i] <<"," <<contadorArrozChaufa << "\n";
				}
				if(pedido[i] == 7)
				{
					fw << platos[i] <<"," <<contadorArrozPollo << "\n";
				}
				if(pedido[i] == 8)
				{
					fw << platos[i] <<"," <<contadorDietaPollo << "\n";
				}
				if(pedido[i] == 9)
				{
					fw << platos[i] <<"," <<contadorTorta << "\n";
				}
				if(pedido[i] == 10)
				{
					fw << platos[i] <<"," <<contadorKeke << "\n";
				}
			}
			
			fw.close();
		}
		else cout << "No se pudo abrir el archivo";
		
		ofstream f;
		f.open("archivoBoleta.txt", ios::out | ios::app);
		
		if (f.is_open())
		{
			time_t hora;
			time(&hora);
			f<<asctime(localtime(&hora));
			f<<"Mesa " <<mesaSeleccionada <<endl;
			
			for (int i = 0; i < contador; i++)
			{
				if(pedido[i] == 1)
				{
					f << platos[i] <<" x " <<contadorEmoliente << "\n";
				}
				if(pedido[i] == 2)
				{
					f << platos[i] <<" x " <<contadorChicha << "\n";
				}
				if(pedido[i] == 3)
				{
					f << platos[i] <<" x " <<contadorEnsalada << "\n";
				}
				if(pedido[i] == 4)
				{
					f << platos[i] <<" x " <<contadorPapa << "\n";
				}
				if(pedido[i] == 5)
				{
					f << platos[i] <<" x " <<contadorFideos << "\n";
				}
				if(pedido[i] == 6)
				{
					f << platos[i] <<" x " <<contadorArrozChaufa << "\n";
				}
				if(pedido[i] == 7)
				{
					f << platos[i] <<" x " <<contadorArrozPollo << "\n";
				}
				if(pedido[i] == 8)
				{
					f << platos[i] <<" x " <<contadorDietaPollo << "\n";
				}
				if(pedido[i] == 9)
				{
					f << platos[i] <<" x " <<contadorTorta << "\n";
				}
				if(pedido[i] == 10)
				{
					f << platos[i] <<" x " <<contadorKeke << "\n";
				}
			}
			
			f.close();
		}
		else cout << "No se pudo abrir el archivo";
		//temporizador(mesaSeleccionada,pedido);
		
		escribirBoletaMesa(pedido, platos, i, contador, contadorEmoliente, contadorChicha, contadorEnsalada, contadorPapa, contadorFideos, contadorArrozChaufa, contadorArrozPollo, contadorDietaPollo, contadorTorta, contadorKeke);
		system("pause");
	}
//}

void escribirBoletaMesa(int pedido[], string platos[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke)
{
	cout<<"//////////          Boleta de pago            \\\\\\\\\\"<<endl;
	cout<<"RESTAURANTE:  EKATERESTAURANTE"<<endl;
	cout<<"De: KOGITA, SAMSGUN S8, FORTINAITI Y ARCANGEL"<<endl;
	cout<<"Venta de quinua tuaques twist, riky tok, caramanducas"<<endl;
	cout<<"Ruc: 10234769730 ------------------------------"<<endl;
	
	printf("%-20s%-10s%-10s%-10s\n","ITEM","CANT","PRECIO","TOTAL");
	for(int i = 0; i < contador; i++)
	{
		if(pedido[i] == 1)
		{
			cout<<platos[i] <<"             ";
			printf("%-10i%-10i%-10i\n",contadorEmoliente,emoliente,emoliente * contadorEmoliente);
			
		}
		if(pedido[i] == 2)
		{
			cout<<platos[i] <<"                ";
			printf("%-10i%-10i%-10i\n",contadorChicha ,chicha,chicha * contadorChicha);
		}
		if(pedido[i] == 3)
		{
			cout<<platos[i] <<"       ";
			printf("%-10i%-10i%-10i\n",contadorEnsalada,ensalada,ensalada * contadorEnsalada);
			
		}
		if(pedido[i] == 4)
		{
			cout<<platos[i] <<"   ";
			printf("%-10i%-10i%-10i\n",contadorPapa,papa,papa * contadorPapa);
			
		}
		if(pedido[i] == 5)
		{
			cout<<platos[i] <<"         ";
			printf("%-10i%-10i%-10i\n",contadorFideos,fideos,fideos * contadorFideos);
		}
		if(pedido[i] == 6)
		{
			cout<<platos[i] <<"          ";
			printf("%-10i%-10i%-10i\n",contadorArrozChaufa,arrozChaufa,arrozChaufa * contadorArrozChaufa);
			
		}
		if(pedido[i] == 7)
		{
			cout<<platos[i] <<"       ";
			printf("%-10i%-10i%-10i\n",contadorArrozPollo,arrozPollo,arrozPollo * contadorArrozPollo);
			
		}
		if(pedido[i] == 8)
		{
			cout<<platos[i] <<"                 ";
			printf("%-10i%-10i%-10i\n",contadorDietaPollo,dietaPollo,dietaPollo* contadorDietaPollo);
			
		}
		if(pedido[i] == 9)
		{
			cout<<platos[i] <<"    ";
			printf("%-10i%-10i%-10i\n",contadorTorta,torta,torta * contadorTorta);
			
		}
		if(pedido[i] == 10)
		{
			cout<<platos[i] <<"     ";
			printf("%-10i%-10i%-10i\n",contadorKeke,keke,keke * contadorKeke);
		}
	}
	system("pause");
	guardarBoleta();
}
#endif

