#ifndef COMPRAPORPRODUCTO_H
#define COMPRAPORPRODUCTO_H

#include <string>
#include "EEnvio.h"
#include "EEnvio.h"
#include "Producto.h"
using namespace std;

class CompraPorProducto{
    private:
        Producto* ptrProducto;
        int cantidadSolicitada;
        EEnvio estadoDeEnvio;

    public:
    CompraPorProducto(Producto* producto, int cantidadSolicitada, EEnvio estadoDeEnvio);
    //GETTERS
    EEnvio getestadoDeEnvio();
    int getCantidadSolicitada();
    int getCodigoProducto();
    string getVendedor();
    void setestadoDeEnvio(EEnvio estadoDeEnvio);
};
#endif // COMPRAPORPRODUCTO_H
