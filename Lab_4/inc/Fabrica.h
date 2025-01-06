#ifndef FABRICA_H
#define FABRICA_H

#include "iControladorUsuarios.h"
#include "iControladorVentas.h"
#include "ControladorUsuarios.h"
#include "ControladorVentas.h"

class Fabrica{
    private:
        static Fabrica * fabricaInst;
        Fabrica();
        ControladorUsuarios* controladorUsuariosInst;
        ControladorVentas* controladorVentasInst;
        
    public:
        static Fabrica * getFabrica();
        iControladorUsuarios *getControladorUsuarios();
        iControladorVentas *getControladorVentas();  
};

#endif // FABRICA_H
