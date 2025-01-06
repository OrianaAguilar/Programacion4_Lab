#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include<iostream>
#include<stdlib.h>
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTInfoEstudiante.h"
#include "Informacion.h"
using namespace std;
class PaginaWeb: public Informacion{
    private:
    string Titulo, Link, Text;
    public: 
    PaginaWeb(int Identificador,const DTFecha& Fecha, string Titulo, string Link, string Text);
    string toString();
    string getTitulo();
    string getLink();
    string getText();
    ~PaginaWeb();
};
#endif
