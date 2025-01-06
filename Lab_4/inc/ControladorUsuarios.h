#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "iControladorUsuarios.h"
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

class ControladorUsuarios : public iControladorUsuarios{
    private:

    static ControladorUsuarios * controladorUsuariosInst;
    ControladorUsuarios();

    // Colecciones:
    map<string, Usuario *> usuarios;
    map<string, Cliente*> clientes;
    map<string, Vendedor*> vendedores;

    // Datos que guarda este controlador:
    int codigoSeleccionado = 0; //seleccionarProducto
    string vendedorProductoSeleccionado; //seleccionarProducto
    int idSeleccionado; //seleccionarComentario
    string comentador; //seleccionarComentario
    int creadorIdComentario = 0;
    char respuestaSeleccionada;
    string usuarioSeleccionado; //seleccionarUsuario
    string nombreNuevoSuscriptor;

    public:
        static ControladorUsuarios* getControladorUsuarios();
        void setCliente(Cliente *cliente);
        void setVendedor(Vendedor *vendedor);
        bool altaCliente(string nickname, string contrasenia, DTFecha fechaNacimiento, DTDireccion direccion, string ciudad);
        bool altaVendedor(string nickname, string contrasenia, DTFecha fechaNacimiento, string codigoRUT);
        set<string> listaDeUsuarios();
        void listaDeVendedores();
        void consultarNotificaciones(string nickname); 
        void eliminarSuscripciones(string nicknameVendedor, string nicknameCliente);
        void listarSuscripciones(string nickname);
        void tipoComentario();
        void seleccionarUsuario_(string nickname);
        Usuario *seleccionarUsuario(string nickname);
        void listarProductos();
        void listarComentarios(int codigo);
        void seleccionarProducto(int codigo, string nickname);
        void seleccionarComentario(int id, string nickname);
        void nuevoComentario(string comentario, DTFecha fechaDeComentario);
        void nuevaRespuesta(string comentario, DTFecha fechaDeComentario);
        void listarComentariosUsuario(string nickname);
        void eliminarComentarioRecursivo(Comentario *comentario);
        void listaDeUsuarios_();
        void infoCliente(string nickname);
        void imprimirListaDeUsuarios();
        void imprimirListaDeVendedores();
        void imprimirListaDeClientes();
        void imprimirSuscripcionesDisponiblesPara(string nickname);
        void suscribirmeA(string nickname);
        bool existenUsuariosRegistrados();
        bool existeNickname(string nickname);
        void getComentarios(Usuario* usuario);
        void imprimirComentarioYRespuestas(Comentario* comentario, set<int>& comentariosImpresos);
        Comentario* buscarComentario(int id, string nickname);
        bool esVendedor(string nickname);
        bool esRutValido(string codigoRUT);
};


#endif // CONTROLADORUSUARIOS_H
