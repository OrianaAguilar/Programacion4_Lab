#ifndef DTINFOPRODUCTO_H
#define DTINFOPRODUCTO_H

#include <string>
#include "ECategoria.h"

using namespace std;

class DTInfoProducto{
    public:
        int codigo;
        string nombre;
        float precio;
        int cantStock;
        string descripcion;
        ECategoria categoria;
        string vendedor;
        const std::string nombreCategoria[3] = {
            "Ropa", "Electrodomesticos", "Otros"
};
        // friend ostream& operator << (std::ostream& os,DTInfoProducto& producto);   
        string toString(); 
        string imprimirInfoRestante();    
        DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor);
        string getDTInfoProducto();
};

#endif // DTINFOPRODUCTO_H 