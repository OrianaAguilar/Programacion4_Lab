#ifndef chatGPT_H
#define chatGPT_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <set>
#include "DTFecha.h"
#include "DTInfoEstudiante.h"
#include "Informacion.h"
using namespace std;

class chatGPT : public Informacion
{
private:
    string pregunta, respuesta;
public:
    chatGPT(int id, const DTFecha &fecha, string pregunta, string respuesta);
    ~chatGPT();
    string getPregunta();
    string getRespuesta();
    string toString();
};

#endif
