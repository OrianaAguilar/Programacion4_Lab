#ifndef DTFECHA_H
#define DTFECHA_H

#include<iostream>
#include<stdlib.h>
#include <string>
using namespace std;
class DTFecha{
    public:
        int dia, mes, anio;
        DTFecha(int dia, int mes, int anio);
        string toString();
};

#endif // DTFECHA_H