#include "DTInfoPromocion.h"

DTInfoPromocion::DTInfoPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, string infoVendedor, map<int,ProductoEnPromocion*> productos) : nombre(nombre), descripcion(descripcion), fechaDeVencimiento(fechaDeVencimiento) ,infoVendedor(infoVendedor), productos(productos)
{}


string DTInfoPromocion::toString(){
    string prodString = "";
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        Producto* prod = it->second->getProducto();
        prodString += "Nombre: " + prod->getNombre() + "\n";
        prodString += "Descripcion: " + prod->getDescripcion() + "\n";
        prodString += "Precio Original: " + to_string(prod->getPrecio()) + "\n";
        prodString += "Cantidad Minima: " + to_string(it->second->getCantMinima()) + "\n";
        prodString += "Descuento: " + to_string(it->second->getDescuento()) + "\n\n";
    }
    return "\nProductos de la promocion " + this->nombre + ":\n" + prodString + "Informacion del vendedor\n" + this->infoVendedor;
}

string DTInfoPromocion::toStringSimple(){
 string prodString = "";
    for (auto it = productos.begin(); it != productos.end(); ++it) {
        Producto* prod = it->second->getProducto();
        prodString += prod->getNombre() + "\n";
    }
    return "Nombre de la promocion: " + this->nombre + 
           "\nDescripcion: " + this->descripcion + 
           "\nProductos en la promocion: " + prodString + 
           "\nFecha de vencimiento: " + this->fechaDeVencimiento.toString() + "\n";

}
