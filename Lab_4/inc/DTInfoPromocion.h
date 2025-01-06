#ifndef DTINFOPROMOCION_H
#define DTINFOPROMOCION_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "Promocion.h"
#include "ProductoEnPromocion.h"

using namespace std;

class DTInfoPromocion{
    public:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        string infoVendedor;
        map<int,ProductoEnPromocion*> productos;

        DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento,string infoVendedor, map<int,ProductoEnPromocion*> productos);
        string toString();
        string toStringSimple();

};

#endif // DTINFOPROMOCION_H