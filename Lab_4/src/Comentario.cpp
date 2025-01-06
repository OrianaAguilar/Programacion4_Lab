#include "Comentario.h"

Comentario::Comentario(int id, string comentario, DTFecha fechaDeComentario) \
            : id(id), comentario(comentario), fechaDeComentario(fechaDeComentario) {}

Comentario::~Comentario(){
    for (map<int, Comentario*>::iterator it = respuestas.begin(); it != respuestas.end(); ++it){
        delete it->second;
    }
    respuestas.clear();
}

int Comentario::getId() const{
    return id;
}
            
string Comentario::getTexto() const{
    return comentario;
}

string Comentario::getAutor() const{
    return autor;
}

DTFecha Comentario::getFecha() const{
    return fechaDeComentario;
}

Producto* Comentario::getProducto() const{
    return producto;
}

void Comentario::setProducto(Producto* producto){
    this->producto = producto;
}

void Comentario::setAutor(string nickname){
    this->autor = nickname;
}

Comentario* Comentario::getComentarioPadre() const{
    return comentarioPadre;
}

int Comentario::getIdComentarioPadre(){
    return comentarioPadre->getId();
}

void Comentario::setComentarioPadre(Comentario* comentarioPadre) {
    this->comentarioPadre = comentarioPadre;
}
void Comentario::agregarRespuesta(Comentario* comentario){
    respuestas[comentario->getId()] = comentario;
}

map<int, Comentario*>& Comentario::getRespuestas(){
    return respuestas;
}

void Comentario::eliminarRespuesta(int id){
    respuestas.erase(id);
}
