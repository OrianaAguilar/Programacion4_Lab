#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <stdlib.h>
#include <set>
#include <string>
#include "Informacion.h"
#include "DTFecha.h"
#include "DTInfoEstudiante.h"

using namespace std;

class Libro: public Informacion{
private:
    string titulo,resumen;
    set<string> autores;
public:
    Libro(int id, const DTFecha& fecha, string titulo, set<string>& autores, string resumen);
    string getTitulo();
    set<string> getAutores();
    string getResumen();
    string toString();
    ~Libro();
};

#endif
