#ifndef ADMINISTRACION_H_INCLUDED
#define ADMINISTRACION_H_INCLUDED
#include <iostream>
#include "Santiago.h"
using namespace std;

void programaAdmin()
{
	int num;
	cout << "1) Mesas" << endl;
	cout << "2) Historial de pedidos" << endl;
	cin >> num;
	
	switch (num)
	{
	case 1:
		cout << "Mesas";
		break;
	case 2:
		boletaPrincipal();
		break;
	}
}

#endif
