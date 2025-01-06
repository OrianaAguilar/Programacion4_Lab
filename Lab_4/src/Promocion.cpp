#include "Promocion.h"

Promocion::Promocion(string nombre, string descripcion, DTFecha fechaDeVencimiento)
    : nombre(nombre), descripcion(descripcion), fechaDeVencimiento(fechaDeVencimiento) {}

void Promocion::agregarProductoPromocion(ProductoEnPromocion* producto){
    this->productos[producto->getProducto()->getCodigo()] = producto;
}

string Promocion::getNombre()
{
    return this->nombre;
}

string Promocion::getDescripcion()
{
    return this->descripcion;
}

DTFecha Promocion::getFechaDeVencimiento()
{
    return this->fechaDeVencimiento;
}

map<int,ProductoEnPromocion*> Promocion::getProductos()
{
    return this->productos;
}
