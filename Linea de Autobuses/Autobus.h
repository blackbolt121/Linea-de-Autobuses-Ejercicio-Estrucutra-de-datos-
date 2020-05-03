#pragma once
#include "Lista.h"
class Autobus
{
public:
	Autobus();
	void suben();
	void bajan();
	int Npasajeros();
	int getTotal();
	void recorrido();
	static int Aleatorio();
	static int Aleatorio2();
private:
	List<int> pasajeros;
	int total;
	int totalBajadas;
	int maxSubida;
	int maxBajada;
};

