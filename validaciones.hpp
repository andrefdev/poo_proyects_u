//validaciones
#include <iostream>

using namespace std;

void validarEnteroMayor1(int n)
{
	while (n < 1)
	{
		cout << "El dato ingresado debe ser mayor a 1: "; 
		cin >> n;
	}
}

void validarQueSeaEntero(int n)
{
	while (int validar = isdigit(n) == 0)
	{
		cout << "El dato ingresado debe ser numerico: ";
		cin >> n;
	}
}