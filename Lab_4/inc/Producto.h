#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>
#include "DTInfoProducto.h"
#include "DTInfoProducto.h"
#include "ECategoria.h"
#include "DTProductoCompra.h"
#include "DTInfoCompra.h"
#include "Comentario.h"

using namespace std;

class Producto{ 
    private:
        int codigo;
        int stock;
        float precio;
        string nombre;
        string descripcion;
        string vendedor;
        ECategoria categoria;
        map<int, Comentario*> comentarios;
        bool enPromocion = false;
        

    public:
        Producto(int codigo, int stock, float precio, string nombre, string descripcion, string vendedor, ECategoria categoria, bool enPromocion);
        //getters y setters:
        DTProductoCompra getDatosProducto();
        DTInfoCompra getDatosCompra();
        DTInfoProducto getInfoProducto();
        int getCodigo();
        int getStock();
        float getPrecio();
        string getNombre();
        string getDescripcion();
        ECategoria getCategoria();
        string getNombreVendedor();
        map<int, Comentario*> getComentarios();
        bool getEnPromocion();
        void agregarComentario(Comentario* comentario);
        void eliminarComentario(int id);
        void setStock(int stock);
        void ahoraEstaEnPromo();
        
};

#endif // PRODUCTO_H
