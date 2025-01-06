#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>
#include <vector>
#include "Estudiante.h"
#include "Informacion.h"
using namespace std;

class Biblioteca{
    private:
    set<Informacion*> InformacionesGuardadas;
    
    public: 
    Biblioteca();
    set<Informacion*> getInformacionesGuardadas();
    void insertarInformacion(Informacion *Informacion);
    void eliminarInformacion(int id);
    vector<DTInfoEstudiante> buscarTermino(string clave);
    ~Biblioteca();
};

#endif