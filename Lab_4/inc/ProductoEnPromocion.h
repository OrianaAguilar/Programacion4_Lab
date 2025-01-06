#ifndef PRODUCTOENPROMOCION_H
#define PRODUCTOENPROMOCION_H

#include "Producto.h"
#include "Promocion.h"
using namespace std;
class Promocion;

class ProductoEnPromocion{
    private:
        Producto* ptrProducto;
        float descuento;
        int cantMinima;
        Promocion* promocion;

    public:
        ProductoEnPromocion(Producto* producto, float descuento, int cantMinima);
        float getDescuento();
        int getCantMinima();
        Producto* getProducto();
        void setPromocion(Promocion* promocion);
        Promocion* getPromocion();
};

#endif // PRODUCTOENPROMOCION_H
