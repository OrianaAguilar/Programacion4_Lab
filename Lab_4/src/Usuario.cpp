#include "Usuario.h"

Usuario::Usuario(string nickname, string contrasenia, DTFecha fechaDeNacimiento)
    : nickname(nickname), contrasenia(contrasenia), fechaDeNacimiento(fechaDeNacimiento) {}

Usuario::~Usuario() {}

string Usuario::getNickname(){
    return this->nickname;
}
string Usuario::getFecha() 
{
    return this->fechaDeNacimiento.toString();

}
