#ifndef COMPRA_H
#define COMPRA_H

#include <string>
#include <set>
#include "DTFecha.h"
#include "ProductoEnPromocion.h"
#include "CompraPorProducto.h"
using namespace std;

class Compra{
    private:
        int id;
        DTFecha fechaDeCompra;
        float montoTotal;
        map<int, CompraPorProducto*> productos;
        string cliente;


    public:
        //GETTERS
        string getFechaDeCompra();
        float getMontoTotal();
        const map<int, CompraPorProducto*>& getProductos() const;
        string getCliente();
        int getId();

        Compra(int id, DTFecha fechaDeCompra, float montoTotal, map<int, CompraPorProducto*> productos, string cliente);
       
};

#endif // COMPRA_H
