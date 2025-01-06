#ifndef MENU_H
#define MENU_H

#include "Fabrica.h"

class Menu{
    private:
        Fabrica *fabrica;

    public:
        void gestionDeUsuarios();
        void gestionDeVentas();
};

#endif // MENU_H
