#include "Fabrica.h"

Fabrica * Fabrica::fabricaInst = NULL;

Fabrica::Fabrica(){

}

Fabrica* Fabrica::getFabrica(){
    if(fabricaInst == NULL){
        fabricaInst = new Fabrica();
    }
    return fabricaInst;
}

iControladorUsuarios* Fabrica::getControladorUsuarios(){
    return this->controladorUsuariosInst->getControladorUsuarios();
}

iControladorVentas* Fabrica::getControladorVentas(){
    return this->controladorVentasInst->getControladorVentas();
}
