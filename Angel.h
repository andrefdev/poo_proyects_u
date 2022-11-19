#ifndef ANGEL_H_INCLUDED
#define ANGEL_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include <ctime>

using namespace std;


void  escribir_historial()
{
	string linea;
    string texto;
    ifstream archivo("archivoBoleta.txt", ios::in | ios::app);

    while(getline(archivo, linea))
    {
        texto=texto+linea+"\n";
    }
    archivo.close();
    cout<< texto <<endl;
}

void  escribir_boleta()
{
	string linea;
	string texto;
	ifstream archivo("boleta.txt", ios::in | ios::app);
	
	while(getline(archivo, linea))
	{
		texto=texto+linea+"\n";
	}
	archivo.close();
	cout<< texto <<endl;
}
    
    
    
void temporizador(int mesa, int orden[])
{
	
	int tiempos[50];
	int cantidad;
	int i=0;
	while(orden[i]!=0)
	{
		switch(orden[i])
		{
		case 1:
			tiempos[i]=1;
			break;
			
		case 2:
			tiempos[i]=1;
			break;
			
		case 3:
			tiempos[i]=3;
			break;
			
		case 4:
			tiempos[i]=3;
			break;
			
		case 5:
			tiempos[i]=10;
			break;
			
		case 6:
			tiempos[i]=12;
			break;
			
		case 7:
			tiempos[i]=14;
			break;
			
		case 8:
			tiempos[i]=7;
			break;
			
		case 9:
			tiempos[i]=3;
			break;
			
		case 10:
			tiempos[i]=3;
			break;
		}
		i++;
		cantidad ++;
	}
	
	int minutos;
	int segundos=0;
	int tiempo_max=0;
	for(i=0;i<cantidad; i++)
	{
		if(tiempo_max<tiempos[i])
		{
			tiempo_max=tiempos[i];
		}
	}
	
	minutos=tiempo_max;
	
	while(true)
	{
		system("cls");
		cout<<"Numero de mesa: "<< mesa <<endl;
		cout<<"Tiempo estimado para terminar la orden:\n\n";
		
		if(minutos==0 && segundos==0)
		{
			break;
		}
		
		if(minutos==0 && segundos<10)
		{
			cout<<"\t"<<minutos<<":0"<<segundos<<endl;
			Sleep(100);
		}
		else
		{
			if(minutos!=0 && segundos==0)
			{
				cout<<"\t"<<minutos<<":0"<<segundos<<endl;
				Sleep(100);
			}
			else
			{
				cout<<"\t"<<minutos<<":"<<segundos<<endl;
				Sleep(100);
			}
		}
		
		if(segundos==0)
		{
			minutos--;
			segundos=60;
		}
		
		if(minutos==0 && segundos==15)
		{
			system("Color 04");
		}
		
		segundos--;
	}
	
	system("cls");
	cout<<"Numero de mesa: "<<mesa<<endl;
	cout<<"Tiempo estimado para terminar la orden:\n";
	cout<<"\t"<<"0:00\n";
	cout<<"\nFIN DEL TIEMPO ESTIMADO";
	system("color 07");
	system("pause");
	system("cls");
	
	
}

#endif // ANGEL_H_INCLUDED
