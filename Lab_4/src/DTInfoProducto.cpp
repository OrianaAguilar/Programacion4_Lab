#include "DTInfoProducto.h"

DTInfoProducto::DTInfoProducto(int codigo, string nombre, float precio, int cantStock, string descripcion,  ECategoria categoria, string vendedor): 
                codigo(codigo), nombre(nombre), precio(precio), cantStock(cantStock), descripcion(descripcion), categoria(categoria), vendedor(vendedor)
{}


string DTInfoProducto::toString(){
    return "Codigo: " + to_string(this->codigo) + " \nNombre: " + this->nombre;
}
;

string DTInfoProducto::imprimirInfoRestante(){
    return "Precio: " + to_string(this->precio)+ "\nCantidad en stock: " + to_string(this->cantStock) +
    "\nDescripcion: " + this->descripcion + "\nCategoria: " + this->nombreCategoria[static_cast<int>(this->categoria)] + "\nVendedor: " + this->vendedor;
}
string DTInfoProducto::getDTInfoProducto(){
    string SuperDTInfoProducto;
    if (categoria==ropa){
        SuperDTInfoProducto += "Nombre: " + nombre + "\n";
        SuperDTInfoProducto += "Precio: " + to_string(precio) + "\n";
        SuperDTInfoProducto += "Descripción: " + descripcion + "\n";
        SuperDTInfoProducto += "Categoria: ropa\n";
        SuperDTInfoProducto += "Cantidad en stock: " + to_string(cantStock) + "\n";
        SuperDTInfoProducto += "Código: " + to_string(codigo) + "\n";
    }
    if (categoria==electrodomesticos){
        SuperDTInfoProducto += "Nombre: " + nombre + "\n";
        SuperDTInfoProducto += "Precio: " + to_string(precio) + "\n";
        SuperDTInfoProducto += "Descripción: " + descripcion + "\n";
        SuperDTInfoProducto += "Categoria: electrodomesticos\n";
        SuperDTInfoProducto += "Cantidad en stock: " + to_string(cantStock) + "\n";
        SuperDTInfoProducto += "Código: " + to_string(codigo) + "\n";
    }
    if (categoria==otros){
        SuperDTInfoProducto += "Nombre: " + nombre + "\n";
        SuperDTInfoProducto += "Precio: " + to_string(precio) + "\n";
        SuperDTInfoProducto += "Descripción: " + descripcion + "\n";
        SuperDTInfoProducto += "Categoria: otros\n";
        SuperDTInfoProducto += "Cantidad en stock: " + to_string(cantStock) + "\n";
        SuperDTInfoProducto += "Código: " + to_string(codigo) + "\n";
    }

    return SuperDTInfoProducto;
}