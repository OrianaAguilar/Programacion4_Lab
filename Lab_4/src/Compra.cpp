#include "Compra.h"
Compra::Compra(int id, DTFecha fechaDeCompra, float montoTotal, map<int, CompraPorProducto *> productos, string cliente) : id(id), fechaDeCompra(fechaDeCompra), montoTotal(montoTotal), productos(productos), cliente(cliente)
{
}

string Compra::getFechaDeCompra() 
{
     return this->fechaDeCompra.toString();
}

float Compra::getMontoTotal()
{
    return this->montoTotal;
}

const map<int, CompraPorProducto*> &Compra::getProductos() const
{
    return this->productos;
}

string Compra::getCliente()
{
    return this->cliente;
}

int Compra::getId()
{
    return this->id;
}
