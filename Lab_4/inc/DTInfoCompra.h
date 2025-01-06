#ifndef DTINFOCOMPRA_H
#define DTINFOCOMPRA_H

#include "DTFecha.h"
#include <set>
#include "DTInfoProducto.h"

class DTInfoCompra{
    public:
        DTFecha fechaDeCompra;
        float montoTotal;
        set<DTInfoProducto> productos;
        DTInfoCompra(DTFecha fechaDeCompra, float montoTotal);
};

#endif // DTINFOCOMPRA_H