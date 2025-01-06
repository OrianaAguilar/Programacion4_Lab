#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include <map>

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "DTFecha.h"
#include "DTcomentario.h"
using namespace std;

class Producto;
class Comentario{
    private:
        int id;
        string comentario;
        string autor;
        DTFecha fechaDeComentario;
        map<int, Comentario*> respuestas;
        Producto* producto;
        Comentario* comentarioPadre = nullptr;

    public:
        Comentario(int id, string comentario, DTFecha fechaDeComentario);
        ~Comentario();
        int getId() const;
        string getTexto() const;
        string getAutor() const;
        DTFecha getFecha() const;
        Producto* getProducto() const;
        void setProducto(Producto* producto);
        void setAutor(string nickname);
        Comentario* getComentarioPadre() const;
        int getIdComentarioPadre();
        void setComentarioPadre(Comentario* comentarioPadre);
        void agregarRespuesta (Comentario* comentario);
        void eliminarRespuesta(int id);
        map<int, Comentario*>& getRespuestas();
};

#endif // COMENTARIO_H
