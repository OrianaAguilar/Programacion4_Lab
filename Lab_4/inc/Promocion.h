#ifndef PROMOCION_H
#define PROMOCION_H

#include <string>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"
#include <map>
using namespace std;

class ProductoEnPromocion;

class Promocion{
    private:
        string nombre;
        string descripcion;
        DTFecha fechaDeVencimiento;
        map<int,ProductoEnPromocion*> productos;

    public:
        Promocion(string nombre, string descripcion, DTFecha fechaDeVencimiento);
        void agregarProductoPromocion(ProductoEnPromocion* producto);
        string getNombre();
        string getDescripcion();
        DTFecha getFechaDeVencimiento();
        map<int,ProductoEnPromocion*> getProductos();
};

#endif // PROMOCION_H
