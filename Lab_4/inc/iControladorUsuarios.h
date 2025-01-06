#ifndef ICONTROLADORUSUARIOS_H
#define ICONTROLADORUSUARIOS_H
#include <string>
#include <vector>
#include <set>
#include <map>
#include "Cliente.h"
#include "DTFecha.h"
#include "Vendedor.h"
#include "Usuario.h"
#include "Cliente.h"
#include "DTcomentario.h"
#include "DTNotificacion.h"
#include "ControladorVentas.h"
#include "DTDireccion.h"
#include "Comentario.h"
using namespace std;

class iControladorUsuarios{
    public:
        virtual ~iControladorUsuarios() = default;
        virtual void setCliente(Cliente *cliente)= 0 ;
        virtual void setVendedor(Vendedor *vendedor)= 0 ;
        virtual bool altaCliente(string nickname, string contrasenia, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad)= 0 ;
        virtual bool altaVendedor(string nickname, string contrasenia, DTFecha fechaNacimiento, string codigoRUT)= 0 ;
        virtual set<string> listaDeUsuarios()= 0 ;
        virtual void listaDeVendedores()= 0 ;
        virtual void consultarNotificaciones(string nickname)= 0 ; 
        virtual void eliminarSuscripciones(string nicknameVendedor, string nicknameCliente)= 0 ;
        virtual void listarSuscripciones(string nickname)= 0 ;
        virtual void tipoComentario()= 0 ;
        virtual void seleccionarUsuario_(string nickname)= 0 ;
        virtual Usuario *seleccionarUsuario(string nickname)= 0 ;
        virtual void listarProductos()= 0 ;
        virtual void listarComentarios(int codigo)= 0 ;
        virtual void seleccionarProducto(int codigo, string nickname)= 0 ;
        virtual void seleccionarComentario(int id, string nickname)= 0 ;
        virtual void nuevoComentario(string comentario, DTFecha fechaDeComentario)= 0 ;
        virtual void nuevaRespuesta(string comentario, DTFecha fechaDeComentario)= 0 ;
        virtual void listarComentariosUsuario(string nickname)= 0 ;
        virtual void eliminarComentarioRecursivo(Comentario *comentario)= 0 ;
        virtual void listaDeUsuarios_()= 0 ;
        virtual void infoCliente(string nickname)= 0 ;
        virtual void imprimirListaDeUsuarios()= 0 ;
        virtual void imprimirListaDeVendedores()= 0 ;
        virtual void imprimirListaDeClientes()= 0 ;
        virtual void imprimirSuscripcionesDisponiblesPara(string nickname)= 0 ;
        virtual void suscribirmeA(string nickname)= 0 ;
        virtual bool existenUsuariosRegistrados()= 0 ;
        virtual bool existeNickname(string nickname)= 0 ;
        virtual Comentario* buscarComentario(int id, string nickname)= 0 ;
        virtual bool esVendedor(string nickname)=0 ;
        virtual bool esRutValido(string codigoRUT)=0;

};

#endif // ICONTROLADORUSUARIOS_H
