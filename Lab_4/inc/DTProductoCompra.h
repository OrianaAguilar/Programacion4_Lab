#ifndef DTPRODUCTOCOMPRA_H
#define DTPRODUCTOCOMPRA_H

#include <string>
using namespace std;

class DTProductoCompra{
public:
    int codigo;
    float precio;
    int cant;
    DTProductoCompra(int codigo, float precio, int cant);
    string toString();
};

#endif // DTPRODUCTOCOMPRA_H