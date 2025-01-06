#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <iostream>
#include <string>

using namespace std;
class DTDireccion{
public:
    string calle;
    int numeroDePuerta;
    DTDireccion(string calle, int numeroDePuerta);
};

#endif // DTDIRECCION_H