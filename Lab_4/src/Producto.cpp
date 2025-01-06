#include "Producto.h"

Producto::Producto(int codigo, int stock, float precio, string nombre, string descripcion, string vendedor, ECategoria categoria, bool enPromocion): 
codigo(codigo), stock(stock), precio(precio), nombre(nombre), descripcion(descripcion), vendedor(vendedor), categoria(categoria), enPromocion(enPromocion) {}





DTProductoCompra Producto::getDatosProducto()
{
    // Implementación
    return DTProductoCompra(0, 0.0, 0);
}

DTInfoCompra Producto::getDatosCompra()
{
    // Implementación
    return DTInfoCompra(DTFecha(1,1,1), 0);
}
   
DTInfoProducto Producto::getInfoProducto(){
    return DTInfoProducto(this->getCodigo(), this->getNombre(), this->getPrecio(), this->getStock(), this->getDescripcion(),  this->getCategoria(),this->getNombreVendedor());
     
}

int Producto::getCodigo()
{
    return this->codigo;
}

int Producto::getStock()
{
    return this->stock;
}

float Producto::getPrecio()
{
    return this->precio;
}

string Producto::getNombre()
{
    return this->nombre;
}

string Producto::getDescripcion()
{
    return this->descripcion;
}

ECategoria Producto::getCategoria()
{
    return this->categoria;
}

string Producto::getNombreVendedor()
{
    return this->vendedor;
}

map<int, Comentario*> Producto::getComentarios(){
    return comentarios;
}

bool Producto::getEnPromocion()
{
    return this->enPromocion;
}

void Producto::agregarComentario(Comentario* comentario){
   comentarios[comentario->getId()] = comentario;
}

void Producto::setStock(int stock){
    this->stock = stock;
}

void Producto::eliminarComentario(int idComentario) {
    map<int, Comentario*>::iterator it = comentarios.find(idComentario);
    if (it != comentarios.end()) {
        comentarios.erase(it->first);
        cout << "Comentario con ID: " << idComentario << " eliminado de Producto.\n";
    } else {
        cout << "Comentario con ID: " << idComentario << " no encontrado en Producto.\n";
    }
}

void Producto::ahoraEstaEnPromo()
{
    this->enPromocion = true;
}