#include "CompraPorProducto.h"

CompraPorProducto::CompraPorProducto(Producto* producto, int cantidadSolicitada, EEnvio estadoDeEnvio): ptrProducto(producto), cantidadSolicitada(cantidadSolicitada), estadoDeEnvio(estadoDeEnvio)
{}

EEnvio CompraPorProducto::getestadoDeEnvio(){
    return this->estadoDeEnvio;
}

int CompraPorProducto::getCantidadSolicitada() {
    return this->cantidadSolicitada;
}


int CompraPorProducto::getCodigoProducto() {
    return this->ptrProducto->getCodigo();
}

string CompraPorProducto::getVendedor(){
    return this->ptrProducto->getNombreVendedor();
}

void CompraPorProducto::setestadoDeEnvio(EEnvio estadoDeEnvio){
    this->estadoDeEnvio = estadoDeEnvio;
}
