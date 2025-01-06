#include "DTProductoCompra.h"

DTProductoCompra::DTProductoCompra(int codigo, float precio, int cant): codigo(codigo), precio(precio), cant(cant){}

string DTProductoCompra::toString(){
    return "Codigo del producto: " + to_string(this->codigo) + "\nCantidad solicitada: " + to_string(this->cant)  + "\n" +" \nPrecio: " + to_string(this->precio) + "\n";
}
