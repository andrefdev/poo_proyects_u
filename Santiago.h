#ifndef BOLETA_H_INCLUDED
#define BOLETA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include "SimonCodigo.h"
#include "SimonFunciones.h"

using namespace std;

const int emoliente = 5;
const int chicha = 6;
const int ensalada = 10;
const int papa = 9;	
const int fideos = 20;
const int arrozChaufa = 23;
const int arrozPollo = 26;
const int dietaPollo = 15;
const int torta = 10;
const int keke = 11;

int montoBase;
float igv;
float totalPago;
int precioEmoliente = 0;
int precioChicha = 0;
int precioEnsalada = 0;
int precioPapa = 0;	
int precioFideos = 0;
int precioArrozChaufa = 0;
int precioArrozPollo = 0;
int precioDietaPollo = 0;
int precioTorta = 0;
int precioKeke = 0;

int contEmoliente = 0;
int contChicha = 0;
int contEnsalada = 0;
int contPapa = 0;	
int contFideos = 0;
int contArrozChaufa = 0;
int contArrozPollo = 0;
int contDietaPollo = 0;
int contTorta = 0;
int contKeke = 0;

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

void escribirBoletaMesa(int pedido[], string platos[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke);

void boleta()
{
	ifstream archivo;		
	archivo.open("archivoIT.txt", ios::in);
	
	if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	vector <string> x;	
	vector <int> y;
	string aux;
	int i = 0;
	int numero;
	
	//itero linea por linea y guardo en vectores los platos y cantidad
	while(!archivo.eof())
	{
		getline(archivo, aux, ',');
		x.push_back(aux);
		
		getline(archivo, aux, '\n');
		istringstream (aux) >> numero;
		y.push_back(numero);
		i++;
	}
	
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i] == "Emoliente")
		{
			contEmoliente += y[i];
			precioEmoliente = contEmoliente * emoliente;
		}
		if(x[i] == "Chicha")
		{
			contChicha += y[i];
			precioChicha = contChicha * chicha;
		}
		if(x[i] == "Ensalada fresca")
		{
			contEnsalada += y[i];
			precioEnsalada = contEnsalada * ensalada;
		}
		if(x[i] == "Papa a la huancaina")
		{
			contPapa += y[i];
			precioPapa = contPapa * papa;
		}
		if(x[i] == "Fideos verdes")
		{
			contFideos += y[i];
			precioFideos = contFideos * fideos;
		}
		if(x[i] == "Arroz chaufa")
		{
			contArrozChaufa += y[i];
			precioArrozChaufa = contArrozChaufa * arrozChaufa;
		}
		if(x[i] == "Arroz con pollo")
		{
			contArrozPollo += y[i];
			precioArrozPollo = contArrozPollo * arrozPollo;
		}
		if(x[i] == "Dieta")
		{
			contDietaPollo += y[i];
			precioDietaPollo = contDietaPollo * dietaPollo;	
		}
		if(x[i] == "Torta de chocolate")
		{
			contTorta += y[i];
			precioTorta = contTorta * torta;
		}
		if(x[i] == "Keke de zanahoria")
		{
			contKeke += y[i];
			precioKeke = contKeke * keke;
		}
	}
	time_t hora;
	time(&hora);
	cout<<asctime(localtime(&hora));
	
	cout<<"La cantidad de emolientes pedidos es: "<<contEmoliente<<"---> $"<<precioEmoliente<<endl;
	cout<<"La cantidad de chichas pedidas es: "<<contChicha<<"---> $"<<precioChicha<<endl;
	cout<<"La cantidad de ensaladas pedidas es: "<<contEnsalada<<"---> $"<<precioEnsalada<<endl;
	cout<<"La cantidad de papas pedidas es: "<<contPapa<<"---> $"<<precioPapa<<endl;
	cout<<"La cantidad de fideos pedidos es: "<<contFideos<<"---> $"<<precioFideos<<endl;
	cout<<"La cantidad de arroz chaufa pedidos es: "<<contArrozChaufa<<"---> $"<<precioArrozChaufa<<endl;
	cout<<"La cantidad de arroz con pollo pedidos es: "<<contArrozPollo<<"---> $"<<precioArrozPollo<<endl;
	cout<<"La cantidad de dietas de pollo pedidas es: "<<contDietaPollo<<"---> $"<<precioDietaPollo<<endl;
	cout<<"La cantidad de tortas pedidas es: "<<contTorta<<"---> $"<<precioTorta<<endl;
	cout<<"La cantidad de kekes pedidos es: "<<contKeke<<"---> $"<<precioKeke<<endl;
	
	montoBase = precioEmoliente + precioArrozChaufa + precioArrozPollo + precioChicha + precioDietaPollo + precioEnsalada + precioFideos + precioKeke + precioPapa + precioTorta;
	igv = montoBase * 0.18;
	totalPago = montoBase + igv;
}

void guardarBoleta()
{
	ofstream a;
	a.open("boleta.txt", ios::out | ios::app);
	
	if (a.is_open())
	{	
		a<<"\t\t\t\t\t\t\t //////////          Boleta de pago            \\\\\\\\\\"<<endl;
		a<<"\t\t\t\t\t\t\t      RESTAURANTE:  EKATERESTAURANTE"<<endl;
		a<<"\t\t\t\t\t\t\t De: KOGITA, SAMSGUN S8, FORTINAITI Y ARCANGEL"<<endl;
		a<<"\t\t\t\t\t\t\t Venta de quinua tuaques twist, riky tok, caramanducas"<<endl;
		a<<"\t\t\t\t\t\t\t Ruc: 10234769730 ------------------------------"<<endl;
		
		time_t hora;
		time(&hora);
		cout<<asctime(localtime(&hora));
		
		if(contEmoliente!=0)
		{
			a<<"La cantidad de emolientes pedidos es: "<<contEmoliente<<"---> $"<<precioEmoliente<<endl;
		}
		if(contChicha!=0)
		{
			a<<"La cantidad de chichas pedidas es: "<<contChicha<<"---> $"<<precioChicha<<endl;
		}
		if(contEnsalada!=0)
		{
			a<<"La cantidad de ensaladas pedidas es: "<<contEnsalada<<"---> $"<<precioEnsalada<<endl;
		}
		if(contPapa!=0)
		{
			a<<"La cantidad de papas pedidas es: "<<contPapa<<"---> $"<<precioPapa<<endl;
		}
		if(contFideos!=0)
		{
			a<<"La cantidad de fideos pedidos es: "<<contFideos<<"---> $"<<precioFideos<<endl;
		}
		if(contArrozChaufa!=0)
		{
			a<<"La cantidad de arroz chaufa pedidos es: "<<contArrozChaufa<<"---> $"<<precioArrozChaufa<<endl;
		}
		if(contArrozPollo!=0)
		{
			a<<"La cantidad de arroz con pollo pedidos es: "<<contArrozPollo<<"---> $"<<precioArrozPollo<<endl;
		}
		if(contDietaPollo!=0)
		{
			a<<"La cantidad de dietas de pollo pedidas es: "<<contDietaPollo<<"---> $"<<precioDietaPollo<<endl;
		}
		if(contTorta!=0)
		{
			a<<"La cantidad de tortas pedidas es: "<<contTorta<<"---> $"<<precioTorta<<endl;
		}
		if(contKeke!=0)
		{
			a<<"La cantidad de kekes pedidos es: "<<contKeke<<"---> $"<<precioKeke<<endl;
		}
		
		montoBase = precioEmoliente + precioArrozChaufa + precioArrozPollo + precioChicha + precioDietaPollo + precioEnsalada + precioFideos + precioKeke + precioPapa + precioTorta;
		igv = montoBase * 0.18;
		totalPago = montoBase + igv;
		
		a<<"La cuenta seria de: "<<montoBase<<endl;
		a<<"Impuestos: "<<igv<<endl;
		a<<"El monto final es de: "<<totalPago<<endl;;
		a.close();
	}
	else cout<<"No se puede abrir el archivo";
	system("cls");
	escribirBoletaMesa(pedido, platos, i, contador, contadorEmoliente, contadorChicha, contadorEnsalada, contadorPapa, contadorFideos, contadorArrozChaufa, contadorArrozPollo, contadorDietaPollo, contadorTorta, contadorKeke);
}


void escribirBoletaMesa(int pedido[], string platos[], int i, int contador, int& contadorEmoliente, int& contadorChicha, int& contadorEnsalada, int& contadorPapa, int& contadorFideos, int& contadorArrozChaufa, int& contadorArrozPollo, int& contadorDietaPollo, int& contadorTorta, int& contadorKeke)
{
cout<<"DESC		CANT	PRECIO UNIT 	TOTAL";
	for(int i = 0; i < contador; i++)
	{
		if(pedido[i] == 1)
		{
			cout<<platos[i] <<" "<<contadorEmoliente << " "<< emoliente <<" "<<emoliente * contadorEmoliente <<endl;
			
		}
		if(pedido[i] == 2)
		{
			cout<<platos[i] <<" "<<contadorChicha << " "<< chicha <<" "<<chicha * contadorChicha <<endl;
		}
		if(pedido[i] == 3)
		{
			cout<<platos[i] <<" "<<contadorEnsalada<< " "<< ensalada <<" "<<ensalada * contadorEnsalada <<endl;
			
		}
		if(pedido[i] == 4)
		{
			cout<<platos[i] <<" "<<contadorPapa<< " "<< papa <<" "<<papa * contadorPapa <<endl;
			
		}
		if(pedido[i] == 5)
		{
			cout<<platos[i] <<" "<<contadorFideos<< " "<< fideos <<" "<<fideos * contadorFideos <<endl;
		}
		if(pedido[i] == 6)
		{
			cout<<platos[i] <<" "<<contadorArrozChaufa<< " "<< arrozChaufa <<" "<< arrozChaufa * contadorArrozChaufa <<endl;
			
		}
		if(pedido[i] == 7)
		{
			cout<<platos[i] <<" "<<contadorArrozPollo<<endl<< " "<< arrozPollo <<" "<<arrozPollo * contadorArrozPollo <<endl;
			
		}
		if(pedido[i] == 8)
		{
			cout<<platos[i] <<" "<<contadorDietaPollo<< " "<< dietaPollo <<" "<<dietaPollo* contadorDietaPollo<<endl;
			
		}
		if(pedido[i] == 9)
		{
			cout<<platos[i] <<" "<<contadorTorta<< " "<< torta <<" "<<torta * contadorTorta <<endl;
			
		}
		if(pedido[i] == 10)
		{
			cout<<platos[i] <<" "<<contadorKeke<< " "<< keke <<" "<<keke * contadorKeke <<endl;
		}
	}
}

void boletaPrincipal()
{
	boleta();
	system("pause");
	guardarBoleta();
}

#endif
