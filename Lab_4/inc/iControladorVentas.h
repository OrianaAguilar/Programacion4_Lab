#ifndef ICONTROLADORVENTAS_H
#define ICONTROLADORVENTAS_H
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include "Cliente.h"
#include "Vendedor.h"
#include "Promocion.h"
#include "Compra.h"
#include "DTInfoPromocion.h"
#include "DTProductoCompra.h"
#include "ECategoria.h"
#include "Producto.h"
#include "DTFecha.h"
#include "DTInfoCompra.h"
using namespace std;

class iControladorVentas{
    public:
        virtual ~iControladorVentas() = default ;
        virtual void listarNicknamesClientes()= 0 ;
        virtual bool seleccionarCliente(string nickname)= 0 ;
        virtual void mostrarDetallesCompra()= 0 ;
        virtual void registrarCompra()= 0 ;
        virtual void setCliente(Cliente *cliente)= 0 ;
        virtual void setVendedor(Vendedor *vendedor)= 0 ;
        virtual void setPromocion(Promocion *promocion)= 0 ;
        virtual void setCompra(Compra *compra)= 0 ;
        virtual void setProducto(Producto *producto)= 0 ;
        virtual map<int, Producto*> getProductos()= 0 ;
        virtual map<string, Vendedor*> getVendedores()= 0 ;
        virtual map<string, Cliente*> getClientes()= 0 ;
        virtual void setFechaPromo(DTFecha fechaPromocion)= 0 ;
        virtual void setFechaActual(DTFecha fechaSistema)= 0 ;
        virtual void listarProductos()= 0 ;
        virtual void consultarProducto(int codigo)= 0 ;
        virtual vector<DTInfoPromocion> crearSetDTInfoPromocion()= 0 ;
        virtual void listarPromociones()= 0 ;
        virtual void consultarPromocion(string nombre)= 0 ;
        virtual void cargarNuevoProducto(string nicknameVendedor,int codigo, string  nombreProd,float  precio , int stock , string  descripcion, ECategoria  categoria, bool enPromocion)= 0 ;
        virtual void altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, float descuentoPromo)= 0 ;
        virtual void seleccionarVendedor(string nickname)= 0 ;
        virtual void infoVendedor(string nickname)= 0 ;
        virtual void listarNicknamesVendedor()= 0 ;
        virtual void agregarProductoCompra(int codigo, int cantMinima)= 0 ;
        virtual void agregarProductoPromo(int codigo, int cantMinima)= 0 ;
        virtual void liberarMemoriaRealizarCompra()= 0 ;
        virtual void ingresarPromocion()= 0 ;
        virtual int listarProductosPendientes(string nickname)= 0 ; //devuelve 1 si existian productos pendientes
        virtual int listarComprasAEnviar(Producto* producto)= 0 ; //devuelve 1 si existen compras pendientes de envio con ese producto
        virtual void compraEnviada(int idCompra, int idProducto, string nickname)= 0 ;
        virtual int compararFechasPromociones(DTFecha fecha)= 0 ;
        virtual void procesarProductosEnPromo()= 0 ;
        virtual bool existeCodigo(int codigo)= 0 ;
        virtual bool vendedorTieneProductos(string nickname) = 0;
        virtual bool alMenosUnProductoPromo() = 0;
        virtual bool existeCompraRealizada(string nickname, int idCompra) = 0;

};

#endif // ICONTROLADORVENTAS_H
