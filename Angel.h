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

void recibir_ticket (int orden[])
{
	int emoliente=0;
	int chicha=0;
	int ensalada=0;
	int papa=0;
	int fideos=0;
	int arrozChaufa=0;
	int arrozPollo=0;
	int dietaPollo=0;
	int torta=0;
	int keke=0;
	int c=0;

	string pedido[50];
while(true)
{
	switch(orden[c])
    {
        case 1:
        pedido[c]="Emoliente";
        emoliente++;
        break;

        case 2:
        pedido[c]="Chicha";
        chicha++;
        break;

        case 3:
        pedido[c]="Ensalada fresca";
        ensalada++;
        break;

        case 4:
        pedido[c]="Papa a la huancaina";
        papa++;
        break;

        case 5:
        pedido[c]="Fideos verdes";
        fideos++;
        break;

        case 6:
        pedido[c]="Arroz chaufa";
        arrozChaufa++;
        break;

        case 7:
        pedido[c]="Arroz con pollo";
        arrozPollo++;
        break;

        case 8:
        pedido[c]="Dieta de pollo";
        dietaPollo++;
        break;

        case 9:
        pedido[c]="Torta de chocolate";
        torta++;
        break;

        case 10:
        pedido[c]="Keke de zanahoria";
        keke++;
        break;
	}
    c++;
    if(orden[c]==0)
    {
   		break;
	}
}
    cout<<"Ticket de orden: "<<endl;
	for(int i = 0; i < c; i++)
	{
		if(orden[i] == 1)
		{
			cout<<pedido[i] <<": "<<emoliente <<endl;
		}
		if(orden[i] == 2)
		{
			cout<<pedido[i] <<": "<<chicha<<endl;
		}
		if(orden[i] == 3)
		{
			cout<<pedido[i] <<": "<<ensalada<<endl;
		}
		if(orden[i] == 4)
		{
			cout<<pedido[i] <<": "<<papa<<endl;
		}
		if(orden[i] == 5)
		{
			cout<<pedido[i] <<": "<<fideos<<endl;
		}
		if(orden[i] == 6)
		{
			cout<<pedido[i] <<": "<<arrozChaufa<<endl;
		}
		if(orden[i] == 7)
		{
			cout<<pedido[i] <<": "<<arrozPollo<<endl;
		}
		if(orden[i] == 8)
		{
			cout<<pedido[i] <<": "<<dietaPollo<<endl;
		}
		if(orden[i] == 9)
		{
			cout<<pedido[i] <<": "<<torta<<endl;
		}
		if(orden[i] == 10)
		{
			cout<<pedido[i] <<": "<<keke<<endl;
		}
	}
}


void temporizador(int mesa, int orden)
{
    int segundos=0, minutos;
    string plato;

    switch(orden)
    {
        case 1:
        plato="Emoliente\n";
        minutos=1;
        break;

        case 2:
        plato="Chicha\n";
        minutos=1;
        break;

        case 3:
        plato="Ensalada fresca\n";
        minutos=3;
        break;

        case 4:
        plato="Papa a la huancaina\n";
        minutos=3;
        break;

        case 5:
        plato="Fideos verdes\n";
        minutos=10;
        break;

        case 6:
        plato="Arroz chaufa\n";
        minutos=12;
        break;

        case 7:
        plato="Arroz con pollo\n";
        minutos=14;
        break;

        case 8:
        plato="Dieta de pollo\n";
        minutos=7;
        break;

        case 9:
        plato="Torta de chocolate\n";
        minutos=3;
        break;

        case 10:
        plato="Keke de zanahoria\n";
        minutos=3;
        break;
    }

	while(true)
    {
    	system("cls");
        cout<<"Numero de mesa: "<< mesa <<endl;
        cout<<"Orden: "<< plato;
        cout<<"Tiempo estimado para terminar la orden:\n\n";

        if(minutos==0 && segundos==0)
        {
        	break;
		}

		if(minutos==0 && segundos<10)
		{
			cout<<"\t"<<minutos<<":0"<<segundos<<endl;
            Sleep(1000);
		}
		else
		{
			if(minutos!=0 && segundos==0)
			{
				cout<<"\t"<<minutos<<":0"<<segundos<<endl;
            	Sleep(1000);
			}
			else
			{
				cout<<"\t"<<minutos<<":"<<segundos<<endl;
            	Sleep(1000);
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
    cout<<"Orden: "<<plato;
    cout<<"Tiempo estimado para terminar la orden:\n";
	cout<<"\t"<<"0:00\n";
	cout<<"\nFIN DEL TIEMPO ESTIMADO";

}

#endif // ANGEL_H_INCLUDED
