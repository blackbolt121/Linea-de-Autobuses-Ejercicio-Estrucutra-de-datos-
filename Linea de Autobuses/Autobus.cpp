#include "Autobus.h"
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using std::cout; 
using std::endl;
Autobus::Autobus()
{
	this->total = 0;
	this->maxBajada = 0;
	this->maxSubida = 0;
	this->totalBajadas = 0;
}
void Autobus::suben()
{
	int suben = Autobus::Aleatorio2();
	if (this->maxBajada < suben) this->maxSubida = suben;
	if (27 < this->Npasajeros()) {
		suben = 0;
	}
	if (this->Npasajeros() > 30) {
		int swap = 30 - this->Npasajeros();
		while (swap > 0) {
			this->pasajeros.pop(0);
			swap--;
		}
	}
	cout << "Suben " << suben << " pasajeros" << endl;
	int aux = this->total+1;
	this->total += suben;
	for (int i = aux; i <= this->total; i++) {
		this->pasajeros.insert(1);
	}
}
void Autobus::bajan() {
	int bajan = Autobus::Aleatorio();
	if (bajan <= this->pasajeros.size()) {
		cout << "Bajan " << bajan << endl;
		if (this->maxBajada < bajan) this->maxBajada = bajan;
		for (int i = 0; i < bajan; i++) {
			this->pasajeros.pop(0);
		}
	}
	else if (this->pasajeros.size() == 0) {

		cout << "El autobus esta vacio, nadie baja" << endl;
	}
	else {
		cout << "Bajan todos" << endl;
		int aux = 0;
		while (0 < this->pasajeros.size()) {
			this->pasajeros.pop(0);
			aux++;
		}
		if (this->maxBajada < aux) this->maxBajada = aux;
	}
}
int Autobus::Npasajeros()
{
	return this->pasajeros.size();
}
int Autobus::getTotal()
{
	return this->total;
}
void Autobus::recorrido() {
	int  j = 0; 
	while (j < 100) {
		cout << "Parada: " << j + 1 << endl;
		cout << "Pasajeros que habian antes de la parada " << this->Npasajeros() << endl;
		this->suben();
		this->bajan();
		//Sleep(300);
		j++;
	}
	double promedio = this->getTotal() / 100;
	cout << promedio<<endl;
	cout << "Total de pasajeros que subieron " << this->getTotal() << endl;
	cout << "Total de pasajeros que no bajaron " << this->Npasajeros() << endl;
	cout << "Promedio de pasajeros que suben " << promedio << endl;
	cout << "Maxima bajada de pasajeros: " << this->maxBajada << endl;
	cout << "Maxima subida de pasajeros: " << this->maxSubida << endl;
}

int Autobus::Aleatorio()
{
	srand((int)time(nullptr));
	int x = rand() % 16;
	if (x < 13) {
		x = rand() % 6 + 10;
	}
	else {
		x = rand() % 10;
	}
	return x;
}

int Autobus::Aleatorio2()
{

	srand((int)time(nullptr));
	int x = rand() % 16;
	if (x < 13) {
		x = rand() % 7 + 9;
	}
	else {
		x = rand() % 6;
	}
	return x;
}
