#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include<iostream>
#include<stdlib.h>
#include <set>
#include <vector>
#include <string>
#include "DTFecha.h"
#include "DTInfoEstudiante.h"
#include "Informacion.h"
using namespace std;

class Informacion;

class Estudiante{
	private: 
		string nombre, email;
		int ci;
		vector<Informacion*> InformacionGuardada;
	public:
		Estudiante(string nombre, int ci, string email);
		~Estudiante();
		string getNombre();
		void setNombre(string nombre);
		int getCi();
		void setCi(int ci);
		string getEmail();
		void setEmail(string email);
		string toString();

		void guardarInformacion(Informacion* info);
		void eliminarLinkInformacion(int id);
		set<string> listarInfo(DTFecha Desde);
};
#endif
