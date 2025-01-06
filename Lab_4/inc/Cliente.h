#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"
#include "iSuscriptor.h"
#include "DTDireccion.h"
#include "Compra.h"
using namespace std;

class Cliente : public Usuario, public iSuscriptor{
    private:
        DTDireccion direccion;
        string ciudadResidencia;
        map<int, Compra*> comprasRealizadas;
        int contadorNotificaciones;
        map<int, DTNotificacion> notificaciones;
        map<int, Comentario *> comentarios;

    public:
        // GETTERS
        string getDireccion();
        string getCiudadResidencia();
        const map<int, Compra*>& getComprasRealizadas() const;
        Cliente(string contrasenia, string nickname, DTFecha fecha, DTDireccion direccion, string ciudadResidencia);
        void notificar(DTNotificacion notificacion) override ;
        string getNicknameSuscriptor() override ;
        bool esVendedor() const override{return false;} 
        map<int, DTNotificacion> getNotificaciones();
        void borrarNotificaciones();
        vector<Comentario> listarComentarios(string) override;
        void agregarComentario (Comentario*);
        map<int, Comentario*>& getComentarios();
        void agregarCompra(Compra* compra);
        void eliminarComentario(int id);
       // bool existeCompra(int id);
};

#endif // CLIENTE_H
