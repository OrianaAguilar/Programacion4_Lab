#ifndef INFORMACION_H
#define INFORMACION_H

#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>
#include <string>
#include "DTFecha.h"
#include "Estudiante.h"

using namespace std;

class Estudiante;

class Informacion{
protected:
    int Identificador;
    DTFecha Fecha;
    vector<Estudiante *> InformacionGuardadaPor;

public:
    Informacion(int id, const DTFecha &fecha);
    void guardadoPor(Estudiante *est);

    vector<Estudiante*> getInformacionGuardadaPor();
    void eliminarLinkEstudiante(int ci);
    int getIdentificador();
    DTFecha getFecha();
    virtual string toString() = 0;
    virtual ~Informacion();
};

#endif