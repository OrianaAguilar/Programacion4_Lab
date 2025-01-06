#include "ControladorVentas.h"
#include "../inc/Producto.h"
#include "ECategoria.h"

ControladorVentas * ControladorVentas::ControladorVentasInst = NULL;

ControladorVentas::ControladorVentas(){
    //Constructor
}

void ControladorVentas::setFechaActual(DTFecha fechaSistema){
    this->fechaActual = fechaSistema;
}

ControladorVentas * ControladorVentas::getControladorVentas(){
	if (!ControladorVentasInst){
		ControladorVentasInst = new ControladorVentas();
	}
	return ControladorVentasInst;
}

void ControladorVentas::setCliente(Cliente *cliente)
{
    this->clientes[cliente->getNickname()] = cliente;
}

void ControladorVentas::setVendedor(Vendedor *vendedor){
    this->vendedores[vendedor->getNickname()] = vendedor;
}

void ControladorVentas::setPromocion(Promocion *promocion){
    this->promociones.insert(promocion);
}

void ControladorVentas::setCompra(Compra *compra){
    this->compras[compra->getId()] = compra;
    // Implementación
}

void ControladorVentas::setFechaPromo(DTFecha fechaPromocion){
    this->fechaVencimientoPromo = fechaPromocion;
}

map<int, Producto*> ControladorVentas::getProductos(){
    return this->productos;
}

map<string, Vendedor*> ControladorVentas::getVendedores()
{
    return this->vendedores;
}

map<string, Cliente *> ControladorVentas::getClientes()
{
    return this->clientes;
}

void ControladorVentas::setProducto(Producto *producto){
    this->productos[producto->getCodigo()] = producto;
}

void ControladorVentas::listarProductos(){
    map<int, Producto*> productos = this->getProductos();
        cout<< "Se muestran los productos: \n" << endl;
        for (auto it = productos.begin(); it != productos.end(); ++it) {
            Producto* producto = it->second;
            DTInfoProducto DTproductoPrueba = producto->getInfoProducto();
            string resultado = DTproductoPrueba.toString();
            cout << resultado << "\n"<< endl;
    } 
}

void ControladorVentas::consultarProducto(int codigo){
    map<int, Producto*> productos = this->getProductos();
    bool encontrado = false;
    auto it = productos.find(codigo);
    
    if (it != productos.end()) {
        Producto* producto = it->second;
        string nombreProd = it->second->getNombre();
        DTInfoProducto DTproductoPrueba = producto->getInfoProducto();
        string resultado = DTproductoPrueba.imprimirInfoRestante();
        cout << "Producto consultado: " << nombreProd << "\n" << endl;
        cout << resultado << "\n" << endl;
        encontrado = true;
    }
    
    if (!encontrado) {
        cout << "No existe ningun producto registrado con el codigo consultado: " << codigo << " \n" << endl;
    }
}


vector<DTInfoPromocion> ControladorVentas::crearSetDTInfoPromocion(){
    set<Promocion*>::iterator it;
    vector<DTInfoPromocion> res;

    for(it=promociones.begin(); it != promociones.end(); ++it){
        Promocion* promocion = *it;

        map<int,ProductoEnPromocion*> prod = (*it)->getProductos();
         if(!prod.empty()){
            ProductoEnPromocion* producto = (*prod.begin()).second; //Obtengo el primer producto de la promocion (porque todos los productos de la promocion son del mismo vendedor
            Producto* prod = producto->getProducto();
            string nombreVendedor = prod->getNombreVendedor();

            auto vendedorIt = vendedores.find(nombreVendedor);
            if(vendedorIt != vendedores.end()){
                string vendedorInfo = vendedorIt->second->toString();
                DTInfoPromocion dtip(promocion->getNombre(), promocion->getDescripcion(), promocion->getFechaDeVencimiento(), vendedorInfo, promocion->getProductos());
                res.push_back(dtip);
            }
         }
    }
    return res;
}

void ControladorVentas::listarPromociones(){
    vector<DTInfoPromocion> listadoPromociones = this->crearSetDTInfoPromocion();
    cout<< "Promociones: \n" << endl;   

for (auto it = listadoPromociones.begin(); it != listadoPromociones.end(); ++it) {
    DTInfoPromocion dtip = *it;
    cout << dtip.toStringSimple() + "------------------------------\n" << endl;   
} 

}

void ControladorVentas::consultarPromocion(string nombre){
    vector<DTInfoPromocion> prom = this->crearSetDTInfoPromocion();
    vector<DTInfoPromocion>::iterator it = find_if(prom.begin(), prom.end(),
                                        [&nombre](const DTInfoPromocion& dtip) {
        return dtip.nombre == nombre;

        });
    if (it != prom.end()) {
       cout << it->toString() + "\n"<< endl;
    } else {
       cout<< "Promoción no encontrada"<< endl;
    }
 
}

void ControladorVentas::listarNicknamesClientes(){
 // Version para imprimir directo en la funcion
    for (const auto& pair : this->clientes) {
        cout<< pair.first + "\n" << endl;
    }
}

bool ControladorVentas::seleccionarCliente(string nickname){
    map<int, Producto*>::iterator it;
    auto cliente = this->clientes.find(nickname);
    bool encontrado = false;

    if(cliente != this->clientes.end()){
        encontrado = true;
        cout << "Cliente seleccionado: " << nickname << endl;
        this->nicknameClienteRealizarCompra = nickname;
        cout << "\nListado de productos: \n" << endl;
        for (it = productos.begin(); it != productos.end(); ++it) {
            Producto* producto = it->second; 
            DTInfoProducto dtip(it->first, producto->getNombre(), producto->getPrecio(), producto->getStock(), producto->getDescripcion(), producto->getCategoria(), producto->getNombreVendedor());

            cout << dtip.getDTInfoProducto() << "\n" << endl;
        }  
    } else {
        cout << "Cliente no encontrado con el nickname proporcionado: " << nickname << endl;

    }
    return encontrado;
}

int ControladorVentas::compararFechasPromociones(DTFecha fecha1){
    int res = 0;
    if ((fecha1.anio != this->fechaActual.anio) || (fecha1.mes != this->fechaActual.mes) || (fecha1.dia != this->fechaActual.dia)) {
        if ((fecha1.anio < this->fechaActual.anio) || ((fecha1.anio == this->fechaActual.anio) && (fecha1.mes < this->fechaActual.mes)) ||
            ((fecha1.anio == this->fechaActual.anio) && (fecha1.mes == this->fechaActual.mes) && (fecha1.dia < this->fechaActual.dia))) {
            res = -1;
        } else {
            res = 1;
        }
    }
    return res;
}    

void ControladorVentas::agregarProductoCompra(int codigo, int cant){
    auto it = this->productos.find(codigo);
    auto codigoProducto = this->datosProductoCompra.find(codigo);
  //  auto codigoProductoPromo = this->productosEnPromo.find(codigo);

    if (it != this->productos.end()) {
        if(codigoProducto == this->datosProductoCompra.end()){
             Producto* producto = it->second;
            if (cant > 0 && cant <= producto->getStock()){
                if(producto->getEnPromocion()){
                    for (auto& promo : this->promociones) {
                        auto it2 = promo->getProductos().find(codigo);
                        if (it2 != promo->getProductos().end()) {
                            ProductoEnPromocion* p = it2->second;
                            if ((p->getCantMinima() <= cant)&& this->compararFechasPromociones(promo->getFechaDeVencimiento())!=-1) {
                                this->productosEnPromo[codigo] = cant;
                            }
                            break;
                        }
                    }
                } 
               float precio = producto->getPrecio();
               this->montoTotalCompra += precio * cant;     
               this->datosProductoCompra.emplace(codigo, DTProductoCompra(codigo, precio, cant));
            
            } else {
            cout << "Cantidad inválida. Debe ser mayor a 0 y no exceder el stock disponible." << endl;
            } 
        }else {
            cout << "El producto con el código " << codigo << " ya se encuentra agregado en la compra." << endl;
        }
    } else {
        cout << "Producto no encontrado con el código proporcionado: " << codigo << endl;
    } 
}

void ControladorVentas::procesarProductosEnPromo(){
    while (!this->productosEnPromo.empty()){
        auto it = this->productosEnPromo.begin();
        int codigoProducto = it->first;
        Promocion *promo = nullptr;
        for (auto &promocion : this->promociones){
            auto productosPromocion = promocion->getProductos();
            auto it2 = productosPromocion.find(codigoProducto);
            if (it2 != productosPromocion.end()){
                promo = promocion;
                break;
            }
        }
        if (promo){
            auto productosPromocion = promo->getProductos();
            bool todosProductosEnPromo = true;
            map<int, int> encontrados;
            for (auto it2 = productosPromocion.begin(); it2 != productosPromocion.end(); ++it2){
                int codigoProdPromo = it2->first;
                if (this->productosEnPromo.find(codigoProdPromo) != this->productosEnPromo.end()){
                    encontrados[codigoProdPromo] = this->productosEnPromo[codigoProdPromo];
                }
                else{
                    todosProductosEnPromo = false;
                    break;
                }
            }
            if (todosProductosEnPromo){
                for (const auto &par : encontrados){
                    int codigoProductoPromo = par.first;
                    int cantidadPromo = par.second;
                    auto itProducto = this->productos.find(codigoProductoPromo);
                    Producto *producto = itProducto->second;
                    float precioOriginal = producto->getPrecio();
                    float descuento = productosPromocion.find(codigoProductoPromo)->second->getDescuento();
                    float precioConDescuento = precioOriginal * (1 - descuento / 100.0);
                    this->montoTotalCompra -= precioOriginal * cantidadPromo;
                    this->montoTotalCompra += precioConDescuento * cantidadPromo;
                    this->datosProductoCompra.erase(codigoProductoPromo);
                    this->datosProductoCompra.emplace(codigoProductoPromo, DTProductoCompra(codigoProductoPromo, precioConDescuento, cantidadPromo));
                }
            }
            else{
                ++it;
            }
            for (const auto &par : encontrados){
                    this->productosEnPromo.erase(par.first);
                }
        }
        else{
            ++it;
        }
    }
}

void ControladorVentas::mostrarDetallesCompra(){
    this->procesarProductosEnPromo();
    cout << "Detalles de la compra: " << endl;

    for (const auto& par : this->datosProductoCompra) {
        DTProductoCompra producto = par.second;
        cout << producto.toString() << endl;
    }
    cout << "Monto total de la compra: " << this->montoTotalCompra << endl;
    
} 

void ControladorVentas::registrarCompra(){
    map<int, CompraPorProducto*> productosCompra;

    for(const auto& par : this->datosProductoCompra){
        Producto* producto = this->productos[par.first];
        producto->setStock(producto->getStock() - par.second.cant);
        
        CompraPorProducto* compraPorProducto = new CompraPorProducto(producto, par.second.cant, EEnvio::pendiente);
        productosCompra[par.first] = compraPorProducto;
    }
    this->idCompra++;
    Compra* compra = new Compra(this->idCompra, this->fechaActual, this->montoTotalCompra, productosCompra, this->nicknameClienteRealizarCompra);
    
    Cliente* cliente = this->clientes[this->nicknameClienteRealizarCompra];
    cliente->agregarCompra(compra);
    this->compras[this->idCompra] = compra;
}

void ControladorVentas::liberarMemoriaRealizarCompra(){
    this->datosProductoCompra.clear();
    this->productosEnPromo.clear();
    this->montoTotalCompra = 0;
    this->nicknameClienteRealizarCompra = "";
}


//el Sistema le asigna un código único al producto y lo da de alta en el sistema.
void ControladorVentas::cargarNuevoProducto(string nicknameVendedor, int codigo, string  nombreProd,float  precio , int stock , string  descripcion,
    ECategoria  categoria, bool enPromocion){

    if(this->productos.find(codigo)==this->productos.end()){
        Producto *P = new Producto(codigo, stock, precio, nombreProd, descripcion, nicknameVendedor, categoria, enPromocion);
        productos[codigo] = P;
        Vendedor *V = vendedores[nicknameVendedor];
        V->agregarProducto(P);
        cout<<"El producto "<<nombreProd<<" fue cargado correctamente para el vendedor "<<nicknameVendedor<<"."<<endl;
    }
    else{
        cout<<"El codigo '"<<codigo <<"' ya esta asociado a otro producto. Vuelva a intentarlo con informacion valida."<<endl;
    }
}

void ControladorVentas::altaPromocion(string nombre, string descripcion, DTFecha fechaDeVencimiento, float descuentoPromo){
    this->nombrePromo = nombre;
    this->descripcionPromo = descripcion;
    this->fechaVencimientoPromo = fechaDeVencimiento;
    this->descuentoPromo = descuentoPromo;
    map<string, Vendedor*>::iterator it;
    cout << "Seleccione un vendedor: " << endl;
    for(it=vendedores.begin(); it != vendedores.end(); ++it){
        Vendedor* vendedor = it->second;
        cout<< vendedor->getNickname() << endl;
    }
}

bool ControladorVentas::vendedorTieneProductos(string nickname){
    Vendedor* vendedor = this->vendedores[nickname];
    return (vendedor->tieneProductos());
}

void ControladorVentas::seleccionarVendedor(string nickname){
    this->nicknameVendedorPromo = nickname;
    Vendedor* vendedor = this->vendedores[nickname];
    vendedor->listarProductosVendedor();
}

void ControladorVentas::agregarProductoPromo(int codigo, int cantMinima){
    Producto* producto = this->productos[codigo];
    if(producto!=NULL && !producto->getEnPromocion() && producto->getNombreVendedor()==this->nicknameVendedorPromo){
        ProductoEnPromocion* produPromo = new ProductoEnPromocion(producto, this->descuentoPromo, cantMinima);
        this->productosPromo.insert(produPromo);
        producto->ahoraEstaEnPromo();
        cout<< "El producto es valido y se agregara correctamente a la promo: "<<endl;
    }
    else cout<< "El producto NO es valido para agregarse correctamente a la promo: "<<endl;
}


void ControladorVentas::ingresarPromocion(){
    if(this->productosPromo.empty()){
        cout<<"No es posible resgistrar una promocion vacia, por favor agregue al menos un producto valido."<<endl;
    }
    else{
    Promocion* promo = new Promocion(this->nombrePromo, this->descripcionPromo, this->fechaVencimientoPromo);
    set<ProductoEnPromocion*>::iterator it;
    map<int, DTInfoProducto> productosPromoDT;
    //int contadorProds = 0;
    Vendedor* vendedor = this->vendedores[this->nicknameVendedorPromo];
    for(it = this->productosPromo.begin(); it!= this->productosPromo.end(); ++it){
        promo->agregarProductoPromocion((*it));
        Producto* prod = (*it)->getProducto();
        DTInfoProducto dtProd = prod->getInfoProducto();
        productosPromoDT.emplace(prod->getCodigo(), dtProd);
        //contadorProds++;
    }
        //(*it)->setPromocion(promo);
    vendedor->notificar(DTNotificacion(this->nicknameVendedorPromo,this->nombrePromo, productosPromoDT));
    this->setPromocion(promo);
    //this->promociones.insert(promo);
    this->productosPromo.clear();
    cout<<"La Promocion se ha ingresado correctamente: "<<endl;
    //Se crea la notificacion asociada a esta promo:
    //this->vendedores[this->nicknameVendedorPromo]->notificar(DTNotificacion(this->nicknameVendedorPromo,this->nombrePromo, productos));
    }
}

int ControladorVentas::listarProductosPendientes(string nickname){
    int existenProductosPendientes = 0;
    set<int> productosListados;
    for (auto compraIt = compras.begin(); compraIt != compras.end(); ++compraIt) {
        Compra* compraActual = compraIt->second;
        for (auto compraPorProducto = compraActual->getProductos().begin(); compraPorProducto != compraActual->getProductos().end(); ++compraPorProducto) {
            CompraPorProducto* productoActual = compraPorProducto->second;
            int codigoProducto = productoActual->getCodigoProducto();
            if ((productoActual->getVendedor() == nickname) && (productoActual->getestadoDeEnvio() == EEnvio::pendiente) && (productosListados.find(codigoProducto) == productosListados.end())) {
                cout << "Producto pendiente de envio: " << codigoProducto << endl;
                productosListados.insert(codigoProducto);
                existenProductosPendientes = 1;
            }
        }
    }
    return existenProductosPendientes;
}

int ControladorVentas::listarComprasAEnviar(Producto *producto){
    int existenComprasAEnviar = 0;
    cout << "Compras pendientes a enviar:" << endl;
    for (auto  compraIt = compras.begin(); compraIt != compras.end(); ++compraIt){
        Compra* compraActual = compraIt->second; 
        for (auto compraPorProducto = compraActual->getProductos().begin() ; compraPorProducto != compraActual->getProductos().end(); ++compraPorProducto)
        {
            CompraPorProducto* productoActual = compraPorProducto->second;
          if ((productoActual->getCodigoProducto() == producto->getCodigo()) && (productoActual->getestadoDeEnvio() == EEnvio::pendiente))
          {
            existenComprasAEnviar = 1;
            cout << "COMPRA: " << compraActual->getId() << endl;
            cout << "  Cliente: " << compraActual->getCliente() << endl;
            cout << "  Fecha de realización: " << compraActual->getFechaDeCompra() << endl;
          }
        }
    }
    return existenComprasAEnviar;
}


void ControladorVentas::compraEnviada(int idCompra, int idProducto, string nickname) {
    Cliente* cliente = clientes.find(nickname)->second;   
    map<int, Compra*> compras = cliente->getComprasRealizadas();    
    map<int, Compra*>::iterator compra = compras.find(idCompra);
    if (!(compra != compras.end()))
    {
        map<int, CompraPorProducto*> prods = compra->second->getProductos();
        CompraPorProducto* productoEnviado = prods.find(idProducto)->second;
        productoEnviado->setestadoDeEnvio(EEnvio::enviado);    
    }
}   

static void imprimirPromoVendedor(string nickname, Promocion* promocion) {
    cout << "Promocion: " << promocion->getNombre() << endl;
    cout << "Descripcion: " << promocion->getDescripcion() << "\n" << endl;
    cout << "Productos en Promocion: " << endl;
    map<int,ProductoEnPromocion*>::iterator prodsIt; 
    map<int,ProductoEnPromocion*> prods = promocion->getProductos(); 
 
    for (prodsIt = prods.begin(); prodsIt != prods.end(); ++prodsIt) {
        ProductoEnPromocion* productoActual = prodsIt->second;
        if (productoActual) {
            cout << "->Producto: " << productoActual->getProducto()->getCodigo() << endl;
            cout << "    Descuento: " << productoActual->getDescuento() << endl;
            cout << "    Cantidad Minima: " << productoActual->getCantMinima() << endl;
        }
    }
}


void ControladorVentas::infoVendedor(string nickname){
    Vendedor* vendedorInfo = vendedores.find(nickname)->second;
    cout << "Nickname: " << vendedorInfo->getNickname() << endl;
    cout << "Fecha de nacimiento: " << vendedorInfo->getFecha() << "\n" << endl;
    cout << "Productos disponibles:" << endl;
    vendedorInfo->listarProductosVendedor();
    cout << "Promociones vigentes:" << endl;
    for (auto enPromo = promociones.begin(); enPromo != promociones.end(); ++enPromo) {
        Promocion* promoActual = *enPromo;
        map<int, ProductoEnPromocion*> mapProd = promoActual->getProductos();
        auto productoVend = mapProd.begin();
        ProductoEnPromocion* ayuda = productoVend->second;
        if (ayuda->getProducto()->getNombreVendedor() == nickname) {
            imprimirPromoVendedor(nickname, promoActual);
        }
    }
}

void ControladorVentas::listarNicknamesVendedor()
{
    for (const auto& pair : this->vendedores) {
        cout<< pair.first + "\n" << endl;
    }
}

bool ControladorVentas::existeCodigo(int codigo){
	if (productos.find(codigo) != productos.end()) {
        return true;
    }
	else return false;
}

bool ControladorVentas::alMenosUnProductoPromo(){
    return !(this->productosPromo.empty());
}

bool ControladorVentas::existeCompraRealizada(string nickname, int idCompra) {
    map<string, Cliente*>::iterator itCliente = this->clientes.find(nickname);
    if (itCliente != this->clientes.end()) {
        map<int, Compra*> compras = itCliente->second->getComprasRealizadas();        
        map<int, Compra*>::iterator itCompra = compras.find(idCompra);
        return itCompra != compras.end();
    }
    return false;
}
