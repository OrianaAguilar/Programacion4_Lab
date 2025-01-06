#include "Cliente.h"

Cliente::Cliente(string nickname, string contrasenia, DTFecha fechaDeNacimiento, DTDireccion direccion, string ciudadResidencia)
    : Usuario(nickname, contrasenia, fechaDeNacimiento), direccion(direccion), ciudadResidencia(ciudadResidencia) {
    this->comentarios = map<int, Comentario*>();
    }

string Cliente::getDireccion()
{
    return "Calle: " +this->direccion.calle+ "\n" + "Numero de puerta: " + to_string(this->direccion.numeroDePuerta) ;
}

string Cliente::getCiudadResidencia()
{
    return this->ciudadResidencia;
}

const map<int, Compra*> &Cliente::getComprasRealizadas() const
{
    return this->comprasRealizadas;
}

void Cliente::notificar(DTNotificacion notificacion){
    int key = this->contadorNotificaciones;
    this->notificaciones.emplace(key,notificacion);
    this->contadorNotificaciones++;
}


map<int, DTNotificacion> Cliente::getNotificaciones(){
    return this->notificaciones;
}

void Cliente::borrarNotificaciones(){
    notificaciones.clear();
    this->contadorNotificaciones = 0;
}

vector<Comentario> Cliente::listarComentarios(string)
{
    return vector<Comentario>();
}

void Cliente::agregarComentario(Comentario *comentario)
{
    this->comentarios.emplace(comentario->getId(), comentario);
}

map<int, Comentario*>& Cliente::getComentarios(){
    return comentarios;
}

void Cliente::agregarCompra(Compra *compra){
    comprasRealizadas[compra->getId()] = compra;
}

string Cliente::getNicknameSuscriptor(){
    return this->getNickname();
}

void Cliente::eliminarComentario(int idComentario) {
    map<int, Comentario*>::iterator it = comentarios.find(idComentario);
    if (it != comentarios.end()) {
        comentarios.erase(it->first);
    }
}

/*bool Cliente::existeCompra(int id)
{
    return (getComprasRealizadas().find(id) != getComprasRealizadas.end())
}*/
