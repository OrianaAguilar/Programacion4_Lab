#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "DTInfoProducto.h"

using namespace std;
class DTNotificacion{
public:
    string nicknameVendedor, nombrePromo;
    map<int, DTInfoProducto> productos;
    DTNotificacion(string nicknameVendedor, string nombrePromo, map<int, DTInfoProducto> productos);
    string getNicknameVendedor();
    string getNombrePromo();
    string getDTInfoProductoNotificacion();
};

#endif // DTNOTIFICACION_H
